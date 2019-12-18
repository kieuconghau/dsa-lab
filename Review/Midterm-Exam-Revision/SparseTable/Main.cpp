#include <iostream>

using namespace std;

struct col {
	int idx;
	int val;
	col* next;
};

struct row {
	int idx;
	row* next;
	col* h_col;
};

struct header {
	int rows;
	int cols;
	int num;
	row* h_row;
};

header* createHeader(int rows, int cols);
row* createRow(int idx);
col* createCol(int idx, int val);

void insertElement(header* h, int rIdx, int cIdx, int val);

bool removeCol(row* h, int idx);
void removeElement(header* h, int rIdx, int cIdx);

void showTable(header* h);

header* convertSparse(int** a, int rows, int cols);

header* createHeader(int rows, int cols) {
	header* h = new header;
	h->num = 0;
	h->rows = rows;
	h->cols = cols;
	h->h_row = createRow(-1); // dummy head
	return h;
}

row* createRow(int idx) {
	row* cre = new row;
	cre->idx = idx;
	cre->next = nullptr;
	cre->h_col = createCol(-1, -1); // dummy head
	return cre;
}

col* createCol(int idx, int val) {
	col* cre = new col;
	cre->idx = idx;
	cre->val = val;
	cre->next = nullptr;
	return cre;
}

void insertElement(header* h, int rIdx, int cIdx, int val) {
	// find row
	row* r2 = h->h_row, * r1 = r2->next;

	while (r1 && r1->idx < rIdx) {
		r2 = r1;
		r1 = r1->next;
	}

	row* insertRow = nullptr;
	if (r1 && r1->idx == rIdx) {
		insertRow = r1;
	}
	else {
		insertRow = createRow(rIdx);
		r2->next = insertRow;
		insertRow->next = r1;
	}

	// find col
	col* c2 = insertRow->h_col, * c1 = c2->next;

	while (c1 && c1->idx < cIdx) {
		c2 = c1;
		c1 = c1->next;
	}

	col* insertCol = nullptr;
	if (c1 && c1->idx == cIdx) {
		cout << "Error: This element has already existed." << endl;
	}
	else {
		insertCol = createCol(cIdx, val);
		c2->next = insertCol;
		insertCol->next = c1;
	}
}

bool removeCol(row* h, int idx) {
	if (h->h_col->next == nullptr) return false;

	col* p = h->h_col; // find prev
	while (p->next != nullptr && p->next->idx != idx) {
		p = p->next;
	}

	if (p->next == nullptr) {
		cout << "Error: Invalid element." << endl;
		return false;
	}

	col* temp = p->next;
	p->next = p->next->next;
	delete temp;
	return true;
}

void removeElement(header* h, int rIdx, int cIdx) {
	if (h->h_row == nullptr || h->h_row->next == nullptr) return;

	if (rIdx > h->rows - 1 || cIdx > h->cols - 1) {
		cout << "Error: Invalid element" << endl;
		return;
	}

	row* p = h->h_row; // find prev
	while (p->next && p->next->idx != rIdx) {
		p = p->next;
	}

	if (p->next == nullptr) {
		cout << "Error: Invalid element." << endl;
		return;
	}

	if (removeCol(p->next, cIdx)) {
		if (p->next->h_col->next == nullptr) { // check after dummy head
			col* dummy = p->next->h_col;
			delete dummy;
			row* temp = p->next;
			p->next = p->next->next;
			delete temp;
		}
		h->num--;
	}
}

void showTable(header* h) {
	if (h == nullptr || h->h_row == nullptr || h->h_row->next == nullptr) return;

	row* r = h->h_row->next; // skip dummy head
	col* c = h->h_row->next->h_col->next; // skip dummy head

	int value;
	for (int i = 0; i < h->rows; ++i) {
		value = 0;
		if (r && r->idx == i) {
			for (int j = 0; j < h->cols; ++j) {
				value = 0;
				if (c && c->idx == j) {
					value = c->val;
					c = c->next;
				}
				cout << "\t" << value;
			}
			r = r->next;
			if (r)
				c = r->h_col->next;
		}
		else {
			for (int j = 0; j < h->cols; ++j) {
				cout << "\t" << value;
			}
		}
		cout << endl;
	}
}

header* convertSparse(int** a, int rows, int cols) {
	header* h = createHeader(rows, cols);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (a[i][j] != 0) {
				insertElement(h, i, j, a[i][j]);
				h->num++;
			}
		}
	}

	return h;
}

int main() {
	int** a = new int* [5];
	a[0] = new int[5]{ 1,0,0,0,0 };
	a[1] = new int[5]{ 0,2,0,0,5 };
	a[2] = new int[5]{ 0,0,0,0,0 };
	a[3] = new int[5]{ 0,2,3,0,0 };
	a[4] = new int[5]{ 1,0,0,4,5 };

	header* h = convertSparse(a, 5, 5);
	showTable(h);

	int r, c;
	cout << "Row = "; cin >> r;
	cout << "Col = "; cin >> c;

	removeElement(h, r, c);

	showTable(h);

	int val;
	cout << "Row = "; cin >> r;
	cout << "Col = "; cin >> c;
	cout << "Val = "; cin >> val;

	insertElement(h, r, c, val);

	showTable(h);
}
