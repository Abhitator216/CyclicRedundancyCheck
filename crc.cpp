#include <vector>
#include <bitset>
#include <iostream>
#include <random>
#include <fstream>
using namespace std;

// using x^8 + x^2 + x + 1 polynomial
uint8_t Crc8(vector<uint8_t> data, int len)
{
  unsigned crc = 0;
  int i, j;
  int idx = 0;
  for (j = len; j; j--, idx++)
  {
    crc ^= (data[idx] << 8); // shift in next byte
    for (i = 8; i; i--)
    {
      if (crc & 0x8000)      // test highest bit
        crc ^= (0x107 << 7); // polynomial
      crc <<= 1;             // shift out
    }
  }
  return (uint8_t)(crc >> 8); // return 8-bit crc
}

bool crcReciever(vector<uint8_t> data, int len)
{
  uint8_t crc = Crc8(data, len);
  if (crc == 0)
  {
    cout << endl;
    for (int i = 0; i < len - 1; i++)
    {
      cout << data[i];
    }
    cout << endl;
    return true;
  }
  return false;
}

void crcSender(vector<uint8_t> input, int n)
{
  uint8_t crc = Crc8(input, n);
  input.push_back(crc);
  vector<uint8_t> original_data = input;
  int random = (rand() % n) % 2;
  int i = 5;
  while (random != 0 && i > 0)
  {
    i--;
    int error = rand() % (8 * (n + 1));
    bitset<8> b(input[error / 8]);
    b.flip(error % 8);
    input[error / 8] = b.to_ulong();
    bool status = crcReciever(input, n + 1);
    if (!status)
    {
      cout << "NAK Received...Resending" << endl;
      input = original_data;
    }
  }

  bool status = crcReciever(input, n + 1);
  cout << "ACK Received..." << endl;
}

int main()
{
  // input data
  int n;
  freopen("output.txt", "w", stdout);
  cin >> n;
  ifstream infile("input.txt");
  char ch;
  vector<uint8_t> fullText;
  while (infile.get(ch))
  {
    fullText.push_back(ch);
  }
  infile.close();
  vector<uint8_t> input;
  for (int j = 0; j < fullText.size(); j += n)
  {
    for (int i = 0; i < n && j + i < fullText.size(); i++)
    {
      input.push_back(fullText[j + i]);
    }
    crcSender(input, input.size());
    input.clear();
  }
  return 0;
}