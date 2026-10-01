#include <iostream>

void freeTable(int ** table, size_t rows)
{
  if (!table)
  {
    return;
  }
  for (size_t i = 0; i < rows; ++i)
  {
    delete[] table[i];
  }
  delete[] table;
}

int ** convert(const int * t, size_t n, const size_t * lns, size_t rows)
{
  size_t total = 0;
  for (size_t i = 0; i < rows; ++i)
  {
    total += lns[i];
  }
  if (total != n)
  {
    return nullptr;
  }

  int ** table = new int * [rows];
  size_t offset = 0;

  for (size_t i = 0; i < rows; ++i)
  {
    table[i] = new int[lns[i]];
    for (size_t j = 0; j < lns[i]; ++j)
    {
      table[i][j] = t[offset++];
    }
  }
  return table;
}

int main()
{
  size_t n = 0;
  size_t rows = 0;

  std::cin >> n >> rows;
  if (!std::cin || rows == 0)
  {
    return 1;
  }

  int * t = new int[n];
  for (size_t i = 0; i < n; ++i)
  {
    std::cin >> t[i];
    if (std::cin.fail())
    {
      delete[] t;
      return 1;
    }
  }

  size_t * lns = new size_t[rows];
  for (size_t i = 0; i < rows; ++i)
  {
    std::cin >> lns[i];
    if (std::cin.fail())
    {
      delete[] t;
      delete[] lns;
      return 1;
    }
  }

  int ** res = convert(t, n, lns, rows);
  if (!res)
  {
    delete[] t;
    delete[] lns;
    return 1;
  }

  for (size_t i = 0; i < rows; ++i)
  {
    if (lns[i] > 0)
    {
      std::cout << res[i][0];
      for (size_t j = 1; j < lns[i]; ++j)
      {
        std::cout << ' ' << res[i][j];
      }
    }
    std::cout << '\n';
  }

  freeTable(res, rows);
  delete[] t;
  delete[] lns;

  return 0;
}
