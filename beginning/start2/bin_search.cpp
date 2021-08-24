#include <iostream>
#include <algorithm>

using namespace std;

void SortVstavka(int n, int massive[])
{
    int elnew, possition;

    for (int i = 1; i < n; i++)
    {
        elnew = massive[i];
        possition = i - 1;
        while(possition >= 0 && massive[possition] > elnew)
        {
            massive[possition+1] = massive[possition];
            possition = possition - 1;
        }
        massive[possition+1] = elnew;
    }
}


int main() {
  setlocale(LC_ALL, "rus");
  cout << "������� ���������� ��������� �������: " << endl;
  int n;
  cin >> n;
  int arr[n];
  int key;

  cout << "������� �������� �������: " << endl;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  SortVstavka(n, arr);

  cout << endl << "������� �������: ";

  cin >> key;

  bool flag = false;
  int l = 0;
  int r = 9;
  int mid;

  while ((l <= r) && (flag != true)) {
    mid = (l + r) / 2;
    if (arr[mid] == key) flag = true;
    if (arr[mid] > key) r = mid - 1;
    else l = mid + 1;
  }

  if (flag) cout << "������ �������� " << key << " � ������� �����: " << mid << endl;
  else cout << "��������, �� ������ �������� � ������� ���" << endl;
  return 0;
}
