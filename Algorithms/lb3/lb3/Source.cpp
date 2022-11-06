#include "Header.h"

static int count1 = 0;
int size(BinaryTree*& Root) {
	if (Root == NULL) return 0;
	count1++;
	size(Root->LeftBranch);
	size(Root->RightBranch);
	return count1;
}


void get_data(BinaryTree* Root, BinaryTree* mass, int count) {
	if (Root != NULL) {
		static int i = 0;
		mass[i].FullName = Root->FullName;
		mass[i].birthdate = Root->birthdate;
		mass[i].mark = Root->mark;
		i++;
		get_data(Root->LeftBranch, mass, count);
		get_data(Root->RightBranch, mass, count);
	}

}



bool Empty(BinaryTree* Root) {
	return (Root == NULL ? true : false);
}

void CreateTree(BinaryTree*& Root, string FullName, int birthdate, short int mark) {

	if (!Root) {
		Root = new BinaryTree;
		Root->FullName = FullName;
		Root->birthdate = birthdate;
		Root->mark = mark;
		Root->LeftBranch = NULL;
		Root->RightBranch = NULL;
		return;
	}
	if (Root->mark > mark)
		CreateTree(Root->LeftBranch, FullName, birthdate, mark);
	else
		CreateTree(Root->RightBranch, FullName, birthdate, mark);

}

void CreateNewTree(BinaryTree*& Root, string FullName, int birthdate, short int mark) {

	if (!Root) {
		Root = new BinaryTree;
		Root->FullName = FullName;
		Root->birthdate = birthdate;
		Root->mark = mark;
		Root->LeftBranch = NULL;
		Root->RightBranch = NULL;
		return;
	}
	if (Root->birthdate > birthdate)
		CreateTree(Root->LeftBranch, FullName, birthdate, mark);
	else
		CreateTree(Root->RightBranch, FullName, birthdate, mark);

}


float avarmarkmark(BinaryTree*& Root) {
	static int avarmark = 0, flag = 0;
	if (Root != NULL) {
		avarmarkmark(Root->LeftBranch);
		avarmark += Root->mark; flag++;
		avarmarkmark(Root->RightBranch);
	}
	return ((float)avarmark / (float)flag);
}


void del(BinaryTree*& Root) {
	if (Root != NULL) {
		del(Root->LeftBranch);
		del(Root->RightBranch);
		delete Root;
		Root = NULL;
	}
}

void pr_obh(BinaryTree*& Root) {
	if (!Root)return;
	cout << " " << Root->FullName << " " << Root->birthdate << " " << Root->mark << "\t\n";
	pr_obh(Root->LeftBranch);
	pr_obh(Root->RightBranch);
}
void zb_obh(BinaryTree*& Root) {
	if (!Root)return;
	zb_obh(Root->LeftBranch);
	zb_obh(Root->RightBranch);
	cout << " " << Root->FullName << " " << Root->birthdate << " " << Root->mark << "\t\n";
}
void sm_obh(BinaryTree*& Root) {
	if (!Root)return;
	sm_obh(Root->LeftBranch);
	cout << " " << Root->FullName << " " << Root->birthdate << " " << Root->mark << "\t\n";
	sm_obh(Root->RightBranch);
}


void del_left_tree(BinaryTree*& Root) {
	if (!Root)return;
	del_left_tree(Root->LeftBranch);
	delete(Root->LeftBranch);
	Root->LeftBranch = NULL;
}
void del_right_tree(BinaryTree*& Root) {
	if (!Root)return;
	del_right_tree(Root->RightBranch);
	delete(Root->RightBranch);
	Root->RightBranch = NULL;
}
void del_branch(BinaryTree*& Root, int mark) {
	if (Root != NULL) {
		if (Root->mark == mark) {
			BinaryTree* ptr = Root;
			if (Root->LeftBranch == NULL && Root->RightBranch == NULL)
				Root = NULL;
			else if (Root->LeftBranch == NULL)
				Root = ptr->RightBranch;
			else if (Root->RightBranch == NULL)
				Root = ptr->LeftBranch;
			else {
				Root = ptr->RightBranch;
				BinaryTree* ptr1;
				ptr1 = Root;
				while (ptr1 != NULL) {
					ptr1 = ptr1->LeftBranch;
					ptr1 = ptr->LeftBranch;
				}
				delete(ptr);
				del_branch(Root, mark);
			}
		}
		else {
			del_branch(Root->LeftBranch, mark);
			del_branch(Root->RightBranch, mark);
		}


	}
}


void Print(BinaryTree** Root, int l) { // test print 
	int i;
	if (*Root != NULL) {
		Print(&((**Root).RightBranch), l + 1);

		for (i = 1; i <= l; i++) cout << "   "; {
			cout << (**Root).FullName << " " << (**Root).birthdate << " " << (**Root).mark << endl;
		}
		Print(&((**Root).LeftBranch), l + 1);
	}
}


int tabs = 0;
void write_trea_in_file(BinaryTree* Root) {
	ofstream fout;
	fout.open("data.txt", fstream::app);
	if (!Root) return;
	tabs += 5;
	write_trea_in_file(Root->RightBranch);
	for (int i = 0; i < tabs; i++) fout << " ";
	fout << Root->FullName << endl;
	for (int i = 0; i < tabs; i++) fout << " ";
	fout << Root->birthdate << endl;
	for (int i = 0; i < tabs; i++) fout << " ";
	fout << Root->mark << endl;
	write_trea_in_file(Root->LeftBranch);
	tabs -= 5;
	return;
	fout.close();
}

static std::string ch_hor = "-", ch_ver = "|", ch_ddia = "/", ch_rddia = "\\", ch_udia = "\\", ch_ver_hor = "|-", ch_udia_hor = "\\-", ch_ddia_hor = "/-", ch_ver_spa = "| ";

void PrintTest(BinaryTree const* node) {
#define _MAX(x, y) ((x) > (y) ? (x) : (y))
#define _MIN(x, y) ((x) < (y) ? (x) : (y))

	auto RepStr = [](std::string const& s, size_t cnt) {
		if (ptrdiff_t(cnt) < 0)
			throw std::runtime_error("RepStr: Bad value " + std::to_string(ptrdiff_t(cnt)) + "!");
		std::string r;
		for (size_t i = 0; i < cnt; ++i)
			r += s;
		return r;
	};
	std::function<std::tuple<std::vector<std::string>, size_t, size_t>(BinaryTree const* node, bool)> Rec;
	Rec = [&RepStr, &Rec](BinaryTree const* node, bool left) {
		std::vector<std::string> lines;
		if (!node)
			return std::make_tuple(lines, size_t(0), size_t(0));
		auto sval = " | " + node->FullName + " | " + std::to_string(node->birthdate) + " | " + std::to_string(node->mark) + " | ";
		//if (sval.size() % 2 != 1) sval += " ";
		auto resl = Rec(node->LeftBranch, true), resr = Rec(node->RightBranch, false);
		auto const& vl = std::get<0>(resl);
		auto const& vr = std::get<0>(resr);
		auto cl = std::get<1>(resl), cr = std::get<1>(resr), lss = std::get<2>(resl), rss = std::get<2>(resr);
		size_t lv = sval.size();
		size_t ls = vl.size() > 0 ? lss : size_t(0);
		size_t rs = vr.size() > 0 ? rss : size_t(0);
		size_t lis = ls == 0 ? lv / 2 : _MAX(int(lv / 2 + 1 - (ls - cl)), 0);
		size_t ris = rs == 0 ? (lv + 1) / 2 : _MAX(int((lv + 1) / 2 - cr), (lis > 0 ? 0 : 1));
		size_t dashls = (ls == 0 ? 0 : ls - cl - 1 + lis - lv / 2), dashrs = (rs == 0 ? 0 : cr + ris - (lv + 1) / 2);
		//DEB(node->value); DEB(lv); DEB(ls); DEB(rs); DEB(cl); DEB(cr); DEB(lis); DEB(ris); DEB(dashls); DEB(dashrs); std::cout << std::endl;
		lines.push_back(
			(ls == 0 ? "" : (RepStr(" ", cl) + ch_ddia + RepStr(ch_hor, dashls))) +
			sval + (rs == 0 ? "" : (RepStr(ch_hor, dashrs) + ch_rddia + RepStr(" ", rs - cr - 1)))
		);
		//if (lines.back().size() != ls + lis + ris + rs)
		//    throw std::runtime_error("Dump: First line wrong size, got " + std::to_string(lines.back().size()) + ", expected " + std::to_string(ls + lis + ris + rs));
		for (size_t i = 0; i < _MAX(vl.size(), vr.size()); ++i) {
			std::string sl = RepStr(" ", ls), sr = RepStr(" ", rs);
			if (i < vl.size()) sl = vl[i];
			if (i < vr.size()) sr = vr[i];
			sl = sl + RepStr(" ", lis);
			sr = RepStr(" ", ris) + sr;
			lines.push_back(sl + sr);
		}
		return std::make_tuple(lines, (left || ls + lis == 0 || lv % 2 == 1) ? ls + lis : ls + lis - 1, ls + lis + ris + rs);
	};
	auto v = std::get<0>(Rec(node, true));
	for (size_t i = 0; i < v.size(); ++i)
		std::cout << v[i] << std::endl;

#undef _MAX
#undef _MIN
}


