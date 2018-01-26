#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

/*Klasa palindrom, której znajdują się wszystkie funkcje potrzebne do dzialania
 * programu. */

class palindrom
{
public:
  vector<string> v; // Struktura danych, w której mamy mozliwosc modyfikacji
                    // rozmiaru tablicy w trakcie życia obiektu.
  int perm(string a, int g);           // Funkcja służąca do permutacji.
  int jestPal(string a, int d, int i); // Funkcja służąca do sprawdzenia czy
                                       // dana permutacja jest palindromem.
  void usuwanie(); // Funkcja służąca do usuwania powtarzających się
                   // palindromów.
  string per;
  int dlugosc;   // Indeks ostatniego znaku w słowie a , czy też per.
  void wypisz(); // Funkcja służąca do wypisania wszystkich palindromów.
  int s = 0;
};

int palindrom::perm(string a, int g) // p-indeks pierwszego znaku w stringu
{
  dlugosc = a.length() - 1; // indeks ostatniego znaku w stringu a
  if (g == dlugosc) {
    // per=a; //przypisanie stringu a do per.
    jestPal(a, s, dlugosc);
  } else {
    for (int i = g; i <= dlugosc; i++) {
      swap(a[i], a[g]); // funkcja zamieniająca i-ty znak z g
      perm(a, g + 1);
      swap(a[i], a[g]);
    }
  }
  return dlugosc;
}

int
palindrom::jestPal(string a, int d, int i)
{
  if (d < i) {
    if (a[d] == a[i]) {
      jestPal(a, d + 1, i - 1);
    } else {
      return 0;
    }
  } else {
    v.push_back(a); // Wpisuje do wektora palindromy.
    return 0;
  }
  return 0;
}

void
palindrom::wypisz()
{
  for (const auto& i : v) {
    cout << i << endl; // wypisujemy całą zawartość vectora v
  }
}

void
palindrom::usuwanie()
{
  sort(v.begin(), v.end()); // sortujemy dane w vectorze
  auto last =
    unique(v.begin(), v.end()); // powtarzające się dane daje na sam koniec
  v.erase(
    last,
    v.end()); // usuwa dane które powtarzały się ( były już na samym końcu)
}

int
main()
{
  palindrom K;
  string a;
  int g = 0;
  cout << "Podaj łańcuch znaków:\n";
  cin >> a;
  cout << "Palindromy:\n";
  K.perm(a, g);
  K.usuwanie();
  K.wypisz();
  return 0;
}
