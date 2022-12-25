#include <iostream>
#include <string>

using namespace std;

struct antrian
{
  char plat[10];
  char jenis[10];
  antrian *next;
};

struct parkir
{
  char plat[10];
  char jenis[10];
  parkir *next;
};

struct antrian *head = NULL;
struct antrian *tail = NULL;
struct parkir *head2 = NULL;
struct parkir *tail2 = NULL;

void tambahAntrian()
{
  antrian *baru;
  baru = new antrian;
  cout << "Masukkan Plat: ";
  cin.ignore();
  cin.getline(baru->plat, 10);
  cout << "Masukkan Jenis: ";
  cin.getline(baru->jenis, 10);
  baru->next = NULL;
  if (head == NULL)
  {
    head = baru;
    tail = baru;
  }
  else
  {
    tail->next = baru;
    tail = baru;
  }
}

void hapusAntrian();
void tambahParkir()
{
  // Menyambungkan antrian ke parkir
  // Jika tambah parkir, maka antrian pertama akan dihapus
  if (head == NULL)
  {
    cout << "Antrian Kosong!" << endl;
    return;
  }
  struct parkir *baru;
  baru = new struct parkir;
  strcpy(baru->plat, head->plat);
  strcpy(baru->jenis, head->jenis);
  baru->next = NULL;
  if (head2 == NULL)
  {
    head2 = baru;
    tail2 = baru;
  }
  else
  {
    tail2->next = baru;
    tail2 = baru;
  }
  hapusAntrian();
}

void tampilAntrian()
{
  antrian *bantu;
  bantu = head;
  if (bantu == NULL)
  {
    cout << "Antrian Kosong!" << endl;
  }
  else
  {
    while (bantu != NULL)
    {
      cout << "Plat: " << bantu->plat << endl;
      cout << "Jenis: " << bantu->jenis << endl
           << endl;
      bantu = bantu->next;
    }
  }
}

void tampilParkir()
{
  parkir *bantu;
  bantu = head2;
  if (bantu == NULL)
  {
    cout << "Parkir Kosong!" << endl;
  }
  else
  {
    while (bantu != NULL)
    {
      cout << "Plat: " << bantu->plat << endl;
      cout << "Jenis: " << bantu->jenis << endl
           << endl;
      bantu = bantu->next;
    }
  }
}

void hapusAntrian()
{
  antrian *hapus;
  hapus = head;
  if (hapus == NULL)
  {
    cout << "Antrian Kosong!" << endl;
  }
  else
  {
    head = hapus->next;
    delete hapus;
  }
}

void hapusParkir()
{
  parkir *hapus;
  hapus = head2;
  if (hapus == NULL)
  {
    cout << "Parkir Kosong!" << endl;
  }
  else
  {
    while (hapus->next != tail2)
    {
      hapus = hapus->next;
    }
    tail2 = hapus;
    hapus = hapus->next;
    tail2->next = NULL;
    delete hapus;
  }
}

int main()
{
  int pilih;

  do
  {
    system("cls");
    cout << "--- MENU ---\n\n";
    cout << "* Program Parkir Dengan Stack dan Queue *\n\n";
    cout << "1. Tambah Antrian\n";
    cout << "2. Tambah Parkir\n";
    cout << "3. Tampilkan Antrian\n";
    cout << "4. Tampilkan Parkir\n";
    cout << "5. Hapus Antrian\n";
    cout << "6. Hapus Parkir\n";
    cout << "\n0. Keluar program\n\n";
    cout << "Pilih : ";
    cin >> pilih;

    switch (pilih)
    {
    case 1:
      tambahAntrian();
      break;
    case 2:
      tambahParkir();
      break;
    case 3:
      tampilAntrian();
      break;
    case 4:
      tampilParkir();
      break;
    case 5:
      hapusAntrian();
      break;
    case 6:
      hapusParkir();
      break;
    default:
      system("cls");
      {
        cout << "pilihan salah!\n"
             << endl;
      }
    }
    system("pause");
  } while (pilih != 6);
}
