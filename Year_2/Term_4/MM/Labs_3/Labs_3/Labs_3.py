from fractions import Fraction
import xlwt
import pulp
import warnings
import numpy as np
from copy import copy, deepcopy

warnings.filterwarnings('ignore', category=UserWarning)


def simplex_method(variables, slack, gomory, basis, A, b, c, original_c):
    num_variables = len(variables)
    num_slack_variables = len(slack)
    num_gomory_variables = len(gomory)

    num_total_variables = num_variables + num_slack_variables + num_gomory_variables
    
    use_dual = num_gomory_variables > 0

    is_success = False
    num_iteration = -1

    while is_success == False:
        num_iteration += 1

        # Update normal and basis variables
        for variable in variables:
            variable.varValue = 0
        for slack_var in slack:
            slack_var.varValue = 0
        for gomory_var in gomory:
            gomory_var.varValue = 0
        for i, basis_var in enumerate(basis):
            index = get_var_index(basis_var, len(variables), len(slack))
            basis_var.varValue = b[i] * A[i][index]

        # Checking for success
        is_success = True
        for i in range(len(c)):
            if (c[i] < 0):
                is_success = False

        is_pivot_set = False
        pivot_column = 0
        pivot_row = 0

        # Checking if all solutions are feasible,
        # if not selecting row of one of them as the pivot row
        for i in range(len(basis)):
            if (basis[i].varValue < 0):
                pivot_row = i
                is_pivot_set = True
                is_success = False

        # Finishing when optimal objective found or when infinite loop is possible
        if (is_success or num_iteration > 10):
            break

        # Getting pivot column
        for i in range(num_total_variables):
            c_i = c[i]
            c_pivot = c[pivot_column]
            if ((compare_as_fraction(c_i, c_pivot, -1) or c_pivot == 0) and c_i != 0):
                pivot_column = i if (not is_pivot_set or A[pivot_row][i] != 0) else pivot_column
            
        # Getting simplex relations
        simplex_relations = []
        for i, A_i in enumerate(A):
            if (A_i[pivot_column] == 0):
                simplex_relations.append(None)
            else:
                simplex_relations.append(b[i] / A_i[pivot_column])

        # Getting pivot row
        if (not is_pivot_set):
            for j, sr_el in enumerate(simplex_relations):
                select_as_pivot = simplex_relations[pivot_row] == None or (sr_el != None and compare_as_fraction(abs(sr_el), abs(simplex_relations[pivot_row]), -1)) if use_dual else simplex_relations[pivot_row] == None or (sr_el != None and (compare_as_fraction(abs(sr_el), abs(simplex_relations[pivot_row]), -1) or simplex_relations[pivot_row] < 0) and sr_el > 0)
                if (select_as_pivot):
                    pivot_row = j

        # Show iteration
        show_iteration(variables, slack, gomory, basis, A, b, simplex_relations, c, num_iteration, is_success, pivot_row, pivot_column)

        # Getting new basis
        if (pivot_column >= num_variables + num_slack_variables):
            basis[pivot_row] = gomory[pivot_column - num_variables - num_slack_variables]
        elif pivot_column >= num_variables:
            basis[pivot_row] = slack[pivot_column - num_variables]
        else:
            basis[pivot_row] = variables[pivot_column]

        # Calculation new b and A
        old_b = copy(b)
        old_A = deepcopy(A)
        for i in range(len(b)):
            if (i == pivot_row):
                b[i] = old_b[i] / old_A[pivot_row][pivot_column]
            else:
                b[i] = old_b[i] - (old_b[pivot_row] / old_A[pivot_row][pivot_column]) * old_A[i][pivot_column]
            for j in range(num_total_variables):
                if (j == pivot_column):
                    A[i][j] = 0 if i != pivot_row else 1
                elif (i == pivot_row):
                    A[i][j] = old_A[i][j] / old_A[pivot_row][pivot_column]
                else:
                    A[i][j] = old_A[i][j] - (old_A[pivot_row][j] / old_A[pivot_row][pivot_column]) * old_A[i][pivot_column]
        
        # Calculating new c
        c = np.zeros(len(c)).tolist()
        for i in range(len(c)):
            for j in range(len(basis)):
                index = get_var_index(basis[j], len(variables), len(slack))
                c[i] += original_c[index] * A[j][i]
            c[i] -= original_c[i]

    # Show iteration
    show_iteration(variables, slack, gomory, basis, A, b, None, c, num_iteration, is_success, None, None)

    return {"variables": variables, "slack": slack, "basis": basis, "is_success": is_success, "A": A, "b": b, "c": c, "original_c": original_c}

def append_A_row(A, i, value):
    for j in range(len(A)):
        A[j].append(value if j == i else 0)

def get_var_index(var, num_variables, num_slack_variables):
    var_type = var.name[0]
    var_number = int(var.name[-1])
    match var_type:
        case "x":
            return var_number - 1
        case "s":
            return num_variables + var_number - 1 
        case "g":
            return num_variables + num_slack_variables + var_number - 1

def compare_as_fraction(num1, num2, compare_method: int):
    match compare_method:
        case 1:
            return Fraction(str(num1)).limit_denominator(100) > Fraction(str(num2)).limit_denominator(100)
        case -1:
            return Fraction(str(num1)).limit_denominator(100) < Fraction(str(num2)).limit_denominator(100)
        case 0:
            return Fraction(str(num1)).limit_denominator(100) == Fraction(str(num2)).limit_denominator(100)
        case _:
            return None
        
def show_iteration(variables, slack, gomory, basis, A, b, simplex_relations, c, num_iteration, is_success, pivot_row, pivot_column):
    table_header = "Базис \t"
    for variable in variables:
        table_header += '{:>5} \t'.format(variable.name)
    for slack_var in slack:
        table_header += '{:>5} \t'.format(slack_var.name)
    for gomory_var in gomory:
        table_header += '{:>5} \t'.format(gomory_var.name)
    table_header += '{:>5} \t{:>5} \t'.format('b', 'ɵ')

    total_var_len = len(variables) + len(slack) + len(gomory)

    print("===========================================================")
    print()
    print(f"Ітерація: {num_iteration + 1}")
    print()
    print(table_header)
    for i in range(len(basis)):
        print(basis[i], end = '\t')
        for j in range(total_var_len):
            print(get_display_number_formated(A[i][j]), end = '\t')
        print(get_display_number_formated(b[i]), end = '\t')
        print('{:>5}'.format('-') if is_success or simplex_relations == None else get_display_number_formated(simplex_relations[i]))
    print('∆i', end = '\t')
    for i in range(total_var_len):
        print(get_display_number_formated(c[i]), end = '\t')
    print()
    print()
    print('Оптимальний план знайдено' if is_success else 'Оптимальний план не знайдено')
    if (not is_success and pivot_row != None and pivot_column != None):
        print(f"Починаємо наступну ітерацію\nПровідний елемент: {get_display_number(A[pivot_row][pivot_column])}")
    print()

def show_lp(name, variables, coefficients, constraints, is_maximization: bool):
    # Create problem model
    problem = pulp.LpProblem("Integer Linear Programming", pulp.LpMaximize if is_maximization else pulp.LpMinimize)

    # Add objective function
    problem += sum(coefficients[i] * variables[i] for i in range(len(coefficients)))

    # Add constraints
    for constraint in constraints:
        match constraint["inequality"]:
            case "<=":
                problem += sum(constraint["coefficients"][i] * variables[i] for i in range(len(coefficients))) <= constraint["value"]
            case ">=":
                problem += sum(constraint["coefficients"][i] * variables[i] for i in range(len(coefficients))) >= constraint["value"]
            case _:
                problem += sum(constraint["coefficients"][i] * variables[i] for i in range(len(coefficients))) == constraint["value"]

    # Show lp
    print()
    print("===========================================================")
    print()
    print(f"{name}:")
    print(f"Z = {problem.objective} -> {'max' if is_maximization else 'min'}")
    for constraint in problem.constraints.values():
        print(constraint)
    print()

def show_results(variables, objective_value, num_variables):
    optimal_plan = ""
    for i in range(num_variables):
        optimal_plan += f"{get_display_number(variables[i].varValue)}, "
    print("Оптимальний план:")
    print(F"x = ({optimal_plan[:-2]}), Z = {get_display_number(objective_value)}")
    print()

def get_display_number(number):
    return '-' if number == None else str(Fraction(str(number)).limit_denominator(100))

def get_display_number_formated(number):
    return '{:>5}'.format(get_display_number(number))


# Input coefficients
num_variables = int(input("Введіть кількість змінних: "))
coefficients = []
for i in range(num_variables):
    coefficient = float(input(f"Введіть коефіцієнт {i+1} цільової функції: "))
    coefficients.append(coefficient)
is_maximization = True if input("Функція мінімізується чи максимізується (min/max): ") == 'max' else False

# Imput constraints
num_constraints = int(input("Введіть кількість обмежень: "))
constraints = []
for i in range(num_constraints):
    constraint_coeffs = []
    for j in range(num_variables):
        coefficient = float(input(f"Введіть коефіцієнт {j+1} обмеження {i+1}: "))
        constraint_coeffs.append(coefficient)
    constraint_inequality = input(f"Введіть знак нерівності обмеження {i+1}: ")
    constraint_value = float(input(f"Введіть значення обмеження {i+1}: "))
    constraints.append({"coefficients": constraint_coeffs, "inequality": constraint_inequality, "value": constraint_value})

# Solving lp
gomory = []

num_variables = len(coefficients)

# Create variables 
variables = []
for i in range(num_variables):
    variable = pulp.LpVariable(f"x{i + 1}", lowBound=0, cat='Integer')
    variables.append(variable)

# Show original
show_lp("Опорний план", variables, coefficients, constraints, is_maximization)

was_changed = False

# Cheking constraints
for constraint in constraints:
    if (constraint["value"] < 0):
        constraint["value"] *= -1
        for i in range(num_variables):
            constraint["coefficients"][i] *= -1
        match constraint["inequality"]:
            case "<=":
                constraint["inequality"] = ">="
            case ">=":
                constraint["inequality"] = "<="
        was_changed = True

if (was_changed):
    show_lp("Оновлена задача", variables, coefficients, constraints, is_maximization)

# A will contain the coefficients of the constraints
A = []

# b will contain the amount of resources
b = []

# c will contain coefficients of objective function L
c = []

for constraint in constraints:
    A.append(constraint["coefficients"])
    b.append(constraint["value"])

for coef in coefficients:
    c.append(coef)

if (not is_maximization):
    print('Шукаємо максимізацію для протилежних знаків')
    print()
    for i in range(num_variables):
        c[i] = -c[i]

slack = []
basis = []

# Add slack and artificial variables
for i, constraint in enumerate(constraints):
    match constraint["inequality"]:
        case "<=":
            slack_var = pulp.LpVariable(f"s{len(slack) + 1}", lowBound=0, cat='Integer')
            slack_var.varValue = 0
            slack.append(slack_var)
            basis.append(slack_var)
            c.append(slack_var.varValue)
            append_A_row(A, i, 1)

        case ">=":
            slack_var = pulp.LpVariable(f"s{len(slack) + 1}", lowBound=0, cat='Integer')
            slack_var.varValue = 0
            slack.append(slack_var)
            basis.append(slack_var)
            c.append(slack_var.varValue)
            append_A_row(A, i, -1)
        
        case "=":
            slack_var = pulp.LpVariable(f"s{len(slack) + 1}", lowBound=0, cat='Integer')
            slack_var.varValue = 0
            slack.append(slack_var)
            basis.append(slack_var)
            c.append(slack_var.varValue)
            append_A_row(A, i, 1)

# Add artifitial variables coefficients to A
for i, constraint in enumerate(constraints):
    match constraint["inequality"]:
        case ">=":
            append_A_row(A, i, 1)

        case "=":
            append_A_row(A, i, 1)

original_c = copy(c)

# Change c signs
for i in range(num_variables):
    c[i] = -c[i]

result = simplex_method(variables, slack, [], basis, A, b, c, original_c)

objective_value = 0

# Limit execution to prevent infinite loop
while len(gomory) < 100:
    variables = result["variables"]
    slack = result["slack"]
    basis = result["basis"]
    is_success = result["is_success"]
    A = result["A"]
    b = result["b"]
    c = result["c"]
    original_c = result["original_c"]

    if (not is_success):
        print('Рішення не знайдено')
        break

    # Find objective
    objective_value = 0
    for i in range(len(variables)):
        objective_value += coefficients[i] * variables[i].varValue

    # Show results
    show_results(variables, objective_value, len(variables))

    # Searh for biggest fractional part
    fract_var = None
    selected_fraction_value = None
    for variable in variables:
        var_fraction_value = round(variable.varValue, 5)
        if (not compare_as_fraction(var_fraction_value % 1, 0, 0) and (selected_fraction_value is None or compare_as_fraction(var_fraction_value % 1, selected_fraction_value % 1, 1))):
            fract_var = variable
            selected_fraction_value = round(fract_var.varValue, 5)

    # Check if we need to apply gomory method
    if (fract_var is None):
        break
    else:
        print('Оптимальний план має дробові значення, використовуємо метод Гоморі')
        print(f'За основу візьмемо змінну {fract_var.name} = {get_display_number(fract_var.varValue)}')
        print()

        # Add new gomory variable
        gomory_var = pulp.LpVariable(f"g{len(gomory) + 1}", lowBound=0, cat='Integer')
        gomory_var.varValue = 0
        gomory.append(gomory_var)
        basis.append(gomory_var)
        c.append(gomory_var.varValue)
        original_c.append(gomory_var.varValue)

        basis_row = 0
        for i in range(len(basis)):
            if (basis[i].name == fract_var.name):
                basis_row = i

        # Add row with negative fractional parts for selected basis row
        y_row = []
        y_b = -abs(b[basis_row] % 1)
        for i in range(len(A[basis_row])):
            y_row.append(-abs(A[basis_row][i] % 1))
        y_row.append(1)

        for i in range(len(A)):
            A[i].append(0)
        A.append(y_row)
        b.append(y_b)

        result = simplex_method(variables, slack, gomory, basis, A, b, c, original_c)

# Export to xls
workbook = xlwt.Workbook()
sheet = workbook.add_sheet("Gomory")

for i, variable in enumerate(variables):
    sheet.write(i, 0, f"x{i + 1}")
    sheet.write(i, 1, variable.varValue)
sheet.write(len(variables), 0, 'Z')
sheet.write(len(variables), 1, objective_value)

workbook.save("Gomory.xls")