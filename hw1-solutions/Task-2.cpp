#include <iostream>

using namespace std;

int main()
{
    unsigned long long egn;
    cin >> egn;

    // ��������� �� ������� �� ������, �����, ��� � ����.
    int year = egn / 100000000ULL;
    egn %= 100000000ULL;
    int mnt = egn / 1000000;
    egn %= 1000000;
    int day = egn / 10000;
    egn %= 10000;
    int city = egn / 100;
    // � egn ������� ���������� ��� ����� - ������� ����� � ��������� �����
    egn %= 100;

    // ����������� ����������� ����
    unsigned factor = 2,
    chSum = (year / 10) * factor;
    factor <<= 1;
    chSum += (year % 10) * factor;
    factor <<= 1;
    chSum += (mnt / 10) * factor;
    factor <<= 1;
    chSum += (mnt % 10) * factor;
    factor <<= 1;
    chSum += (day / 10) * factor;
    factor <<= 1;
    chSum += (day % 10) * factor;
    factor <<= 1;
    chSum += (city / 10) * factor;
    factor <<= 1;
    chSum += (city % 10) * factor;
    factor <<= 1;
    chSum += (egn / 10) * factor;
    // ������� ������� �� ����� 11 � ��� � 10 �� ������ 0
    chSum = (chSum % 11) % 10;

    // ��������� ���� �� ������
    bool male = (egn / 10) % 2 == 0;

    // � egn �������� ���� ���������� ����� - ��������� �����
    egn %= 10;

    // ������������� ��������
    year += 1900;
    // ��� ������ � ������ ����� 1900
    if (mnt > 20 && mnt < 40)
    {
        mnt -= 20;
        year -= 100;
    }

    // ��� ������ � ������ ���� 2000
    if (mnt > 40)
    {
        mnt -= 40;
        year += 100;
    }

    // ������ �������� - ��������� �� ��������� ����, ����� � ��� > 0
    if (chSum != egn || mnt < 1 || mnt > 12 || day < 1)
    {
        cout << "Bad input data!" << endl;
        return 0;
    }

    // ���������� �� ����� � ���������� �����
    int dayMnt = 31;
    switch(mnt)
    {
        case 2: dayMnt -= 2;
        case 4: case 6: case 9: case 11: dayMnt -= 1;
    }

    // �������� �� ��������� ������
    if (mnt == 2 && (year % 4 == 0 && year % 100 || year % 400 == 0))
        dayMnt+=1;

    // ��������� ����������� �� ����
    if (day > dayMnt)
    {
        cout << "Bad input data!" << endl;
        return 0;
    }

    // ���� ������ �������� �� ��������� - ��������� ������� � ��������� ������.
    cout << (day < 10 ? "0" : "") << day << '.'
         << (mnt < 10 ? "0" : "") << mnt << '.'
         << year << " "
         << (male ? 'M' : 'F') << endl;

    return 0;
}
