#include "ImageLib.h"
#include "CTensor.h"
#include <ctime>
using namespace std;

// ��Ȯ�ϰ� ���۽� 20�� (�κ����� ����)

void print_all_elements(const Tensor3D& tensor) {
	int nH, nW, nC;
	tensor.get_info(nH, nW, nC); 
	for (int c = 0; c < nC; c++) {
		cout << c << "-th channel:" << endl;
		for (int h = 0; h < nH; h++) {
			for (int w = 0; w < nW; w++) {
				cout << setw(4) << tensor.get_elem(h, w, c);
			}
			cout << endl;
		}
	}
}

int main() {
	clock_t start = clock();

	int nH = 2; // ���� ���� 
	int nW = 3; // ���� ����
	int nC = 2; // ä���� ���� 
	Tensor3D tensor(nH, nW, nC); // nH x nW x nC ũ���� 3���� ��� ����

	// 
	tensor.set_elem(0, 0, 0, 1);
	tensor.set_elem(1, 1, 0, 2);
	tensor.set_elem(0, 0, 1, 3);
	tensor.set_elem(1, 2, 1, 4);

	print_all_elements(tensor);

	tensor.print();

	clock_t end = clock();
	double elapsed = double(end - start) / CLOCKS_PER_SEC;
	cout << "Processing time: " << elapsed << " seconds" << endl;

	system("PAUSE");

	return 0;
}
