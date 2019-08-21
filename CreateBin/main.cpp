// CreateBin.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
// 0 - 127 までの輝度を使用し輝度数に応じたpixel
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

	// 輝度:0-127 loop
	for (size_t i = 0; i < 128; i++)
	{
		// 輝度数分のpixel数輝度値を書き出して出力
		for (size_t j = 0; j < i; j++)
		{
			for (size_t k = 0; k < 4; k++)
			{
				// bin 4byte書き込み
				ofs.write(reinterpret_cast<char *>(&i), sizeof(char));
			}
		}
	}

	// close
	ofs.close();

	return 0;
}


