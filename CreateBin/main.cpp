// CreateBin.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
// 0 - 127 �܂ł̋P�x���g�p���P�x���ɉ�����pixel
//

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	cout << "start" << endl;
	ofstream ofs("data.bin", ios::binary);

	if (ofs.bad()) {
		cout << "error" << endl;
	}

	// �P�x:0-127 loop
	for (size_t i = 0; i < 128; i++)
	{
		// �P�x������pixel���P�x�l�������o���ďo��
		for (size_t j = 0; j < i; j++)
		{
			for (size_t k = 0; k < 4; k++)
			{
				// bin 4byte��������
				ofs.write(reinterpret_cast<char *>(&i), sizeof(char));
			}
		}
	}

	// close
	ofs.close();

	return 0;
}


