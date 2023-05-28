using System;//
using System.ComponentModel;//
using System.Globalization;
using System.Linq;
using System.Text;//
using System.Collections.Generic;//
using System.Xml.Linq;//
using System.Net.Sockets;//
using System.Reflection;
using System.IO;
using System.IO.Pipes;
using System.Security.Policy;
using System.Collections;
using BookStore;

namespace BookStore
{

    class DataLogicException : Exception
    {
        public DataLogicException(string message) : base(message) { }
        public DataLogicException(string message, Exception innerException) : base(message, innerException) { }
    }

    public interface IName<T> where T : IComparable
    {
        string Name { get; }
        decimal Price { get; }
        decimal GetPrice();
        void SetName(T name);
        void SetPrice(decimal price);
    }

    public interface CostChanged
    {
        event Action<decimal> CostChanged;
    }

    /////////////BASE CLASS FOR ALL PRODUCTS/////////////

    public class Product : IName<string>, IComparable<Product>, CostChanged
    {
        public event Action<decimal> CostChanged;
        public string Name { get; protected set; }
        public decimal Price { get; protected set; }
        public Product()
        {
            Name = "Unknown";
            Price = -1;
        }

        public Product(string names, decimal prices)
        {
            Name = names;
            Price = prices;
        }

        public override string ToString()
        {
            return "Name:" + Name + "\n" + "Price:" + Price;
        }
        public void SetName(string name) { Name = name; }
        public void SetPrice(decimal price) { Price = price; }
        public int CompareTo(Product obj) { return Name.CompareTo(obj); }

        decimal IName<string>.GetPrice() { return Price; }

    }

    /////////////CLASS BOOK////////////////////

    public class Book : Product, IName<string>, IComparable<Book>
    {
        public string BookName { get; private set; }
        public string AuthorName { get; private set; }

        public Book() : base()
        {
            BookName = "Unknown";
            AuthorName = "Unknown";
        }

        public Book(string name, decimal price, string bookName, string authorName) : base(name, price)
        {
            BookName = bookName;
            AuthorName = authorName;
        }
        public override string ToString()
        {
            return base.ToString() + "\nBook:" + BookName + "\nAuthor:" + AuthorName;
        }
        public int CompareTo(Book obj) { return Name.CompareTo(obj); }
    }
    public class SingleBook : Book, IName<string>, IComparable<SingleBook>
    {

        public SingleBook() : base() { }
        public SingleBook(string name, decimal price, string bookName, string authorName) : base(name, price, bookName, authorName) { }
        public override string ToString()
        {
            return base.ToString() + "\nQuantity of books: 1";

        }
        public int CompareTo(SingleBook obj) { return Name.CompareTo(obj); }
    }
    public class BookSeries : Book, IName<string>, IComparable<BookSeries>
    {

        public BookSeries() : base() { }
        public BookSeries(string name, decimal price, string bookName, string authorName) : base(name, price, bookName, authorName) { }
        public override string ToString()
        {
            return base.ToString() + "\nThis book is one of the serie of books";
        }
        public int CompareTo(BookSeries obj) { return Name.CompareTo(obj); }
    }

    /////////////CLASS BOOKMARKS SET////////////////////

    public class BookmarksSet : Product, IName<string>, IComparable<BookmarksSet>
    {
        public string Colour { get; private set; }
        public float QuantityInSet { get; private set; }

        public BookmarksSet() : base()
        {
            Colour = "Unknown";
            QuantityInSet = 0;
        }

        public BookmarksSet(string name, decimal price, string colour, float quantity) : base(name, price)
        {
            Colour = colour;
            QuantityInSet = quantity;
        }

        public override string ToString()
        {
            return base.ToString() + "\nColour:" + Colour + "\nQuantity:" + QuantityInSet;
        }
        public int CompareTo(BookmarksSet obj) { return Name.CompareTo(obj); }
    }
    public class TranslucentBookmarks : BookmarksSet, IName<string>, IComparable<TranslucentBookmarks>
    {
        TranslucentBookmarks() : base() { }
        public TranslucentBookmarks(string name, decimal price, string colour, float quantity) : base(name, price, colour, quantity) { }
        public override string ToString()
        {
            return base.ToString() + "\nThis set is translucent";
        }
        public int CompareTo(TranslucentBookmarks obj) { return Name.CompareTo(obj); }
    }
    public class OpaqueBookmarks : BookmarksSet, IName<string>, IComparable<OpaqueBookmarks>
    {
        OpaqueBookmarks() : base() { }
        public OpaqueBookmarks(string name, decimal price, string colour, float quantity) : base(name, price, colour, quantity) { }
        public override string ToString()
        {
            return base.ToString() + "\nThis set is opaque";
        }
        public int CompareTo(OpaqueBookmarks obj) { return Name.CompareTo(obj); }
    }

    /////////////CLASS POSTERS////////////////////

    public class Posters : Product, IName<string>, IComparable<Posters>
    {
        public char Size { get; private set; }

        public Posters() : base()
        {
            Size = ' ';
        }

        public Posters(string name, decimal price, char size) : base(name, price)
        {
            Size = size;
        }

        public override string ToString()
        {

            return base.ToString() + "\nSize:" + Size;
        }
        public int CompareTo(Posters obj) { return Name.CompareTo(obj); }
    }
    public class Coloured : Posters, IName<string>, IComparable<Coloured>
    {
        public Coloured() : base() { }
        public Coloured(string name, decimal price, char size) : base(name, price, size) { }
        public override string ToString()
        {
            return base.ToString() + "\nColoured: Yes";
        }
        public int CompareTo(Coloured obj) { return Name.CompareTo(obj); }
    }
    public class UnColoured : Posters, IName<string>, IComparable<UnColoured>
    {
        public UnColoured() : base() { }
        public UnColoured(string name, decimal price, char size) : base(name, price, size) { }
        public override string ToString()
        {
            return base.ToString() + "\nColoured: No";
        }
        public int CompareTo(UnColoured obj) { return Name.CompareTo(obj); }
    }

    /////////////CLASS CONTEINER////////////////////

    public class ArrayIterator<T> : IEnumerator<T> where T : IName<string>
    {
        private Container<T> container;
        private int currentIndex = -1;

        public ArrayIterator(Container<T> container)
        {
            this.container = container;
        }

        public bool MoveNext()
        {
            currentIndex++;
            return currentIndex < container.count;
        }

        public void Reset()
        {
            currentIndex = -1;
        }

        public T Current
        {
            get
            {
                return container[currentIndex];
            }
        }

        object IEnumerator.Current
        {
            get
            {
                return Current;
            }
        }

        public void Dispose()
        {
            // No resources to dispose
        }
    }

    public class Container<T> : IEnumerable<T> where T : IName<string>
    {
        private T[] products;
        public int count;
        private decimal totalValue;

        public Container()
        {
            count = 0;
            products = new T[count];
            totalValue = 0;
        }

        public event EventHandler<decimal> TotalValueChanged;

        
        /////////////SEARCH BY////////////////////
        public T this[int index]
        {
            get
            {
                if (index < 0 || index >= count)
                {
                    throw new DataLogicException("\t\tProduct with index" + index + "not found.");
                }
                return products[index];
            }
            set
            {
                if (index < 0 || index >= count)
                {
                    throw new DataLogicException("\t\tProduct with index" +index + "not found.");
                }
                products[index] = value;
            }
        }

        public T this[string name]
        {
            get
            {
                for (int i = 0; i < count; i++)
                {
                    if (products[i].Name == name)
                    {
                        return products[i];
                    }
                }
                throw new KeyNotFoundException("\t\tProduct with name" + name + "not found.");//
            }
            set
            {
                for (int i = 0; i < count; i++)
                {
                    if (products[i].Name == name)
                    {
                        products[i] = value;
                        return;
                    }
                }
                throw new KeyNotFoundException("\t\tProduct with name" + name + "not found.");//
            }
        }

        public T this[decimal price]
        {
            get
            {
                for (int i = 0; i < count; i++)
                {
                    if (products[i].Price == price)
                    {
                        return products[i];
                    }
                }
                throw new KeyNotFoundException("\t\tProduct with price" + price + "not found.");//
            }
            set
            {
                for (int i = 0; i < count; i++)
                {
                    if (products[i].Price == price)
                    {
                        products[i] = value;
                        return;
                    }
                }
                throw new KeyNotFoundException("\t\tProduct with price" + price + "not found.");//
            }
        }
        /////////////ADD////////////////////
        public void AddProduct(T product)
        {
            T[] temp = new T[count + 1];
            for (int i = 0; i < count; i++)
            {
                temp[i] = products[i];
            }
            temp[count] = product;
            products = temp;
            count++;
            totalValue += product.Price;
            TotalValueChanged?.Invoke(this, totalValue);
        }
        /////////////DELETE////////////////////
        public void DeleteProduct(int index)
        {
            if (index < 0 || index >= count)
            {
                Console.WriteLine();
                Console.WriteLine("Invalid index.");
            }
            else
            {
                T deletedProduct = products[index];
                T[] temp = new T[count - 1];
                for (int i = 0; i < index; i++)
                {
                    temp[i] = products[i];
                }
                for (int i = index; i < count - 1; i++)
                {
                    temp[i] = products[i + 1];
                }
                products = temp;
                count--;
                totalValue -= deletedProduct.Price;
                TotalValueChanged?.Invoke(this, totalValue);
                Console.WriteLine();
                Console.WriteLine("\t\tProduct with index " +index+" deleted.");
            }
        }
        /////////////SORTING////////////////////
        public void SortProducts(Comparison<T> comparison)
        {
            Container<T> sortedList = new Container<T>();
            for (int i = 0; i < count; i++)
            {
                sortedList.AddProduct(products[i]);
            }
            for (int i = 0; i < count - 1; i++)
            {
                for (int j = i + 1; j < count; j++)
                {
                    if (comparison(sortedList[i], sortedList[j]) > 0)
                    {
                        T tempProduct = sortedList[i];
                        sortedList[i] = sortedList[j];
                        sortedList[j] = tempProduct;
                    }
                }
            }
            Console.WriteLine("Products sorted: ");
            sortedList.PrintSortedProducts();
        }

        public void PrintSortedProducts()
        {
            foreach (T product in products)
            {
                Console.WriteLine(product);
            }
        }

        public void PrintProducts()
        {
            Console.WriteLine("Products:");
            foreach (T product in products)
            {
                Console.WriteLine(product.ToString());
            }
        }

        /////////////TOTAL COST////////////////////
        public event Action<decimal> TotalCostChanged;
        public decimal GetTotalCost()
        {
            decimal totalCost = 0;
            foreach (T item in this)
            {
                PropertyInfo valueProperty = item.GetType().GetProperty("Price");
                decimal itemCost = (decimal)valueProperty.GetValue(item);
                totalCost += itemCost;
            }
            return totalCost;
        }
        private void OnCostChange(decimal cost)
        {
            TotalCostChanged?.Invoke(GetTotalCost());
        }

        public bool IsEmpty()
        {
            return count == 0;
        }

        public IEnumerator<T> GetEnumerator()
        {
            return new ArrayIterator<T>(this);
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }

        public IEnumerable<T> Reverse()
        {
            for (int i = count - 1; i >= 0; i--)
            {
                yield return products[i];
            }
        }

        public IEnumerable<T> FindByName(string substring)
        {
            foreach (T product in products)
            {
                if (product.Name.Contains(substring))
                {
                    yield return product;
                }
            }
        }

        public IEnumerable<T> Ordered()
        {
            for (int i = 0; i < count; i++)
            {
                yield return products[i];
            }
        }

        public void WriteToBinaryFile(string fileName)
        {
            using (FileStream stream = new FileStream(fileName, FileMode.Create))
            using (BinaryWriter writer = new BinaryWriter(stream))
            {
                writer.Write(count);

                foreach (T product in products)
                {
                    Type type = product.GetType();

                    writer.Write(product.GetType().Name);
                    writer.Write(type.Name);
                    writer.Write(product.GetPrice());
                    if (product is SingleBook singlebook)
                    {
                        writer.Write(singlebook.BookName.Length);
                        writer.Write(singlebook.BookName);
                        writer.Write(singlebook.AuthorName.Length);
                        writer.Write(singlebook.AuthorName);
                    }
                    else if (product is BookSeries bookseries)
                    {
                        writer.Write(bookseries.BookName.Length);
                        writer.Write(bookseries.BookName);
                        writer.Write(bookseries.AuthorName.Length);
                        writer.Write(bookseries.AuthorName);
                    }
                    else if (product is TranslucentBookmarks translucentbookmarks)
                    {
                        writer.Write(1);
                        writer.Write(translucentbookmarks.Colour);
                        writer.Write(1);
                        writer.Write(translucentbookmarks.QuantityInSet);
                    }
                    else if (product is OpaqueBookmarks classiccorn)
                    {
                        writer.Write(1);
                        writer.Write(classiccorn.Colour);
                        writer.Write(1);
                        writer.Write(classiccorn.QuantityInSet);
                    }
                    else if (product is Coloured coloured)
                    {
                        writer.Write(coloured.Size);
                    }
                    else if (product is UnColoured uncoloured)
                    {
                        writer.Write(uncoloured.Size);
                    }
                }
            }
        }

        public void ReadFromBinaryFile(string path)
        {
            using (FileStream stream = new FileStream(path, FileMode.Open))
            using (BinaryReader reader = new BinaryReader(stream))
            {
                int newCount = reader.ReadInt32();
                T[] newProducts = new T[newCount];

                for (int i = 0; i < newCount; i++)
                {
                    string typeName = reader.ReadString();
                    string name = reader.ReadString();
                    decimal price = reader.ReadDecimal();
                    T product;
                    if (typeName == "SingleBook")
                    {
                        int bookNameeLength = reader.ReadInt32();
                        string BookName = reader.ReadString();
                        int authorNameLength = reader.ReadInt32();
                        string authorName = reader.ReadString();
                        product = (T)(object)new SingleBook(name, price, BookName, authorName);
                    }
                    else if (typeName == "BookSeries")
                    {
                        int bookNameeLength = reader.ReadInt32();
                        string BookName = reader.ReadString();
                        int authorNameLength = reader.ReadInt32();
                        string authorName = reader.ReadString();
                        product = (T)(object)new BookSeries(name, price, BookName, authorName);
                    }
                    else if (typeName == "TranslucentBookmarks")
                    {
                        int colourLength = reader.ReadInt32();
                        string colour = reader.ReadString();
                        int quantityinsetLength = reader.ReadInt32();
                        float quantityinset = reader.ReadSingle();
                        product = (T)(object)new TranslucentBookmarks(name, price, colour, quantityinset);
                    }
                    else if (typeName == "OpaqueBookmarks")
                    {
                        int colourLength = reader.ReadInt32();
                        string colour = reader.ReadString();
                        int quantityinsetLength = reader.ReadInt32();
                        float quantityinset = reader.ReadSingle();
                        product = (T)(object)new OpaqueBookmarks(name, price, colour, quantityinset);
                    }
                    else if (typeName == "Coloured")
                    {
                        //int sizeLength = reader.ReadInt32();
                        char size = reader.ReadChar();
                        product = (T)(object)new Coloured(name, price, size);
                    }
                    else if (typeName == "UnColoured")
                    {
                        //int sizeLength = reader.ReadInt32();
                        char size = reader.ReadChar();
                        product = (T)(object)new UnColoured(name, price, size);
                    }
                    else
                    {
                        product = (T)(object)new Product(name, price);
                    }

                    newProducts[i] = product;
                }

                count = newCount;
                products = newProducts;
            }
        }
        /////////////LINQ////////////////////
        public (T cheapest, T mostExpensive) FindCheapestAndMostExpensive()
        {
            T cheapest = products.OrderBy(p => p.Price).FirstOrDefault();
            T mostExpensive = products.OrderByDescending(p => p.Price).FirstOrDefault();
            return (cheapest, mostExpensive);
        }

        public IEnumerable<(string Category, decimal AveragePrice)> GetAveragePriceByCategory()
        {
            var groupedProducts = products.GroupBy(p => p.GetType().Name);

            return groupedProducts.Select(g => (g.Key, g.Average(p => p.Price)));
        }
        /////////////DELEGATES////////////////////
        public T Find(Predicate<T> predicate)
        {
            return Array.Find(products, predicate);
        }

        public IEnumerable<T> FindAll(Predicate<T> predicate)
        {
            return Array.FindAll(products, predicate);
        }
    }
}

/////////////MAIN PART////////////////////
class Program
{

    static void Main(string[] args)
    {
        Container<Product> ChoosedProdukts = new Container<Product>();
        while (true)
        {
            Console.WriteLine("\t\tWelcome to the Book Store!");
            Console.WriteLine("\t\tPlease, choose an operation!");
            Console.WriteLine("\t\t1 -- Buy Books");
            Console.WriteLine("\t\t2 -- Buy Set of Bookmarks");
            Console.WriteLine("\t\t3 -- Buy Posters");
            Console.WriteLine("\t\t4 -- View Choosed Products");
            Console.WriteLine("\t\t5 -- Delete a Choosed Product");
            Console.WriteLine("\t\t6 -- Sort produkts by name");
            Console.WriteLine("\t\t7 -- Search a product");
            Console.WriteLine("\t\t8 -- Save information");
            Console.WriteLine("\t\t9 -- Load new information");
            Console.WriteLine("\t\t10 -- Total cost");
            Console.WriteLine("\t\t11 -- The cheapest and most expensive products");
            Console.WriteLine("\t\t12 -- Average cost by category");
            Console.WriteLine("\t\t0 -- Exit");

        MCH: int select = -1;
            try
            {
                select = int.Parse(Console.ReadLine());
            }
            catch (FormatException ex)
            {
                Console.WriteLine("Uncorrect choice. Please try one more time. (・・ )?");
                goto MCH;
            }

            switch (select)
            {
                case 1:
                    BuyBook(ChoosedProdukts);
                    Console.WriteLine("\n\n");
                    break;
                case 2:
                    BuyBookmarksSet(ChoosedProdukts);
                    Console.WriteLine("\n\n");
                    break;
                case 3:
                    BuyPosters(ChoosedProdukts);
                    Console.WriteLine("\n\n");
                    break;
                case 4:
                    PrintBy(ChoosedProdukts);
                    Console.WriteLine("\n\n");
                    break;
                case 5:
                    RemoveChoosedProdukts(ChoosedProdukts);
                    Console.WriteLine("\n\n");
                    break;

                case 6:
                    ChoosedProdukts.SortProducts((x, y) => x.Name.CompareTo(y.Name));
                    break;
                case 7:
                    SearchBy(ChoosedProdukts);
                    Console.WriteLine("\n\n");
                    break;
                case 8:
                    ChoosedProdukts.WriteToBinaryFile("inf.txt");
                    Console.WriteLine("Success! File have been saved!");
                    Console.WriteLine("\n\n");
                    break;
                case 9:
                    ChoosedProdukts.ReadFromBinaryFile("inf.txt");
                    Console.WriteLine("Success! File have been loaded!");
                    Console.WriteLine("\n\n");
                    Console.Write(ChoosedProdukts);
                    Console.WriteLine("\n\n");
                    break;
                case 10:
                    decimal totalcost = ChoosedProdukts.GetTotalCost();
                    Console.WriteLine("\n\nTotal cost: " + totalcost + "\n\n");
                    break;
                case 11:
                    var (cheapest, mostExpensive) = ChoosedProdukts.FindCheapestAndMostExpensive();
                    Console.WriteLine($"\n\nCheapest product: \n{cheapest}\n\n");
                    Console.WriteLine($"\n\nMost expensive product: \n{mostExpensive}\n\n");
                    break;

                case 12:
                    var averagePricesByCategory = ChoosedProdukts.GetAveragePriceByCategory();
                    foreach (var item in averagePricesByCategory)
                    {
                        Console.WriteLine("\n\nCategory: " + item.Category + ", Average price: " + item.AveragePrice + "\n\n");
                    }
                    break;
                case 0:
                    Console.WriteLine("Thank you for shopping with us!");
                    return;
                default:
                    Console.WriteLine("Uncorrect choice. Please try one more time. (・・ )?");
                    break;
            }
        }
        Console.WriteLine("Thank you for shopping with us!");
        Console.ReadLine();

    }
    static void BuyBook(Container<Product> ChoosedProdukts)
    {
        Console.WriteLine("You`re choosing a book.");
        Console.WriteLine("Please enter the kind of book and genre (f.e. Book.Detective or Manga.Fantasy or Comics.Adventures):");
        string genre = Console.ReadLine();

        Console.WriteLine("Please enter the price of the book:");
        decimal price = decimal.Parse(Console.ReadLine());

        Console.WriteLine("Please enter the name of the book:");
        string bookName = Console.ReadLine();

        Console.WriteLine("Please enter the name of the author:");
        string authorName = Console.ReadLine();

        Console.WriteLine("Please, choose type of book!");
        Console.WriteLine("1 -- Single Book");
        Console.WriteLine("2 -- Book Series");
    BOOKTYPE: int select;
        try
        {
            select = int.Parse(Console.ReadLine());
        }
        catch (FormatException ex)
        {
            Console.WriteLine("Oops.. Fail! Unknown product!(・・ )?");
            goto BOOKTYPE;
        }
        if (select == 1)
        {
            SingleBook book = new SingleBook(genre, price, bookName, authorName);
            Console.WriteLine("\n" + book + "\n");
            ChoosedProdukts.AddProduct(book);
        }
        else if (select == 2)
        {
            BookSeries book = new BookSeries(genre, price, bookName, authorName);
            Console.WriteLine("\n" + book + "\n");
            ChoosedProdukts.AddProduct(book);
        }
        else Console.WriteLine("Oops.. Fail! Unknown product!(・・ )?");
    }
    static void BuyBookmarksSet(Container<Product> ChoosedProdukts)
    {
        Console.WriteLine("You`re choosing a set of bookmarks.");
        Console.WriteLine("Please enter the name of the set (f.e. Spring):");
        string name = Console.ReadLine();

        Console.WriteLine("Please enter the price of the set:");
        decimal price = decimal.Parse(Console.ReadLine());

        Console.WriteLine("Please enter the colour of the set (f.e. Green):");
        string colour = Console.ReadLine();


        Console.WriteLine("Please enter the quantity of the bookmarks in set:");
        float quantity = float.Parse(Console.ReadLine());

        Console.WriteLine("Select type of bookmarks set!");
        Console.WriteLine("1 -- Translucent Bookmarks");
        Console.WriteLine("2 -- Opaque Bookmarks");
    BOOKMARKSTYPE: int select;
        try
        {
            select = int.Parse(Console.ReadLine());
        }
        catch (FormatException ex)
        {
            Console.WriteLine("Oops.. Fail! Unknown product!(・・ )?");
            goto BOOKMARKSTYPE;
        }
        if (select == 1)
        {
            TranslucentBookmarks bookmarks = new TranslucentBookmarks(name, price, colour, quantity);
            Console.WriteLine("\n" + bookmarks + "\n");
            ChoosedProdukts.AddProduct(bookmarks);
        }
        else if (select == 2)
        {
            OpaqueBookmarks bookmarks = new OpaqueBookmarks(name, price, colour, quantity);
            Console.WriteLine("\n" + bookmarks + "\n");
            ChoosedProdukts.AddProduct(bookmarks);
        }
        else Console.WriteLine("Oops.. Fail! Unknown product!(・・ )?");
    }
    static void BuyPosters(Container<Product> ChoosedProdukts)
    {
        Console.WriteLine("You`re choosing posters.");
        Console.WriteLine("Please enter the name of poster`s fandom (f.e. Avengers):");
        string name = Console.ReadLine();

        Console.WriteLine("Please enter the price of the poster:");
        decimal price = decimal.Parse(Console.ReadLine());

        Console.WriteLine("Please enter the size of the corn bucket (S - A4 M - A3 L - A2 XL - A1 XXL - A0):");
        char size = char.Parse(Console.ReadLine());

        Console.WriteLine("Should your poster be cloured? ( Y or N )");
    POSTERSTYPE: char choice;
        try
        {
            choice = char.Parse(Console.ReadLine());
        }
        catch (FormatException ex)
        {
            Console.WriteLine("Oops.. Fail! Unknown product!(・・ )?");
            goto POSTERSTYPE;
        }
        if (choice == 'Y')
        {
            Coloured poster = new Coloured(name, price, size);
            Console.WriteLine("\n" + poster + "\n");
            ChoosedProdukts.AddProduct(poster);
        }
        else if (choice == 'N')
        {
            UnColoured poster = new UnColoured(name, price, size);
            Console.WriteLine("\n" + poster + "\n");
            ChoosedProdukts.AddProduct(poster);
        }
        else Console.WriteLine("Oops.. Fail! Unknown product!(・・ )?");

    }
    static void RemoveChoosedProdukts(Container<Product> ChoosedProdukts)
    {
        Console.WriteLine("Enter the index of removing produkt:");
        int productToDelete;
        int.TryParse(Console.ReadLine(), out productToDelete);

        try
        {
            ChoosedProdukts.DeleteProduct(productToDelete);
        }
        catch (Exception ex) { Console.WriteLine(ex.ToString()); }

    }
    static void SearchBy(Container<Product> ChoosedProdukts)
    {
        Console.WriteLine("Please, choose type of searching!");
        Console.WriteLine("1 -- Search by index");
        Console.WriteLine("2 -- Search by price");
        Console.WriteLine("3 -- Search by name");
        Console.WriteLine("0 -- Back");
    DCH: int choice = -1;
        try
        {
            choice = int.Parse(Console.ReadLine());
        }
        catch (FormatException ex)
        {
            Console.WriteLine("Oops.. Fail! Unknown product!(・・ )?");
            goto DCH;
        }
        switch (choice)
        {
            case 1:
                Console.Write("Input your index -- ");
                int index = int.Parse(Console.ReadLine());
                Console.WriteLine("\n" + ChoosedProdukts[index] + "\n");
                break;

            case 2:
                Console.Write("Input your price -- ");
                decimal price = decimal.Parse(Console.ReadLine());
                Console.WriteLine("\n" + ChoosedProdukts[price] + "\n");
                break;

            case 3:
                Console.Write("Input your name -- ");
                string name = Console.ReadLine();
                Console.WriteLine("\n" + ChoosedProdukts[name] + "\n");
                break;

            case 0:
                break;

            default:
                Console.WriteLine("\n\t\tOops.. Fail! Unknown product!(・・ )?\n");
                break;
        }

    }
    static void PrintBy(Container<Product> ChoosedProdukts)
    {
        Console.WriteLine("Please, choose type of searching!");
        Console.WriteLine("1 -- Print in initial order");
        Console.WriteLine("2 -- Print in reverse order");
        Console.WriteLine("0 -- Back");
    PCH: int choice = -1;
        try
        {
            choice = int.Parse(Console.ReadLine());
        }
        catch (FormatException ex)
        {
            Console.WriteLine("Oops.. Fail! Unknown product!(・・ )?");
            goto PCH;
        }
        switch (choice)
        {
            case 1:
                foreach (Product p in ChoosedProdukts.Ordered())
                {
                    Console.WriteLine(p);
                }
                break;
            case 2:
                foreach (Product p in ChoosedProdukts.Reverse())
                {
                    Console.WriteLine(p);
                }
                break;

            case 0:
                break;

            default:
                Console.WriteLine("\n\t\tOops.. Fail! Unknown product!(・・ )?\n");
                break;
        }

    }
}