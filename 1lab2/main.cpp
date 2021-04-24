#include "Shifr.h"
#include <locale>
#include <codecvt>
int main()
{
    bool vihod = true;
    string rejime,stroka;
    cout << "Здравствуйте, пора что-нибудь зашифровать/расшифровать!" << endl;
  
 do {
        locale loc("ru_RU.UTF-8");
        locale::global(loc);
        cout << "Пожалуйста, укажите режим работы:\n encode - шифрование\n decode - расшифрование\n exit - завершение работы программы "<< endl;
        cin >> rejime;
if (rejime == "encode") {
            cout << "Введите строку для шифрования:"<<endl; cin >> stroka;
            int kluch;
            cout << "Введите ключ:"<<endl; cin >> kluch;
            Shifr zashifr(kluch);
            wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
            wstring wstren = codec.from_bytes(stroka);
            cout<<codec.to_bytes(zashifr.enshifr(zashifr,wstren))<<endl;
        }       
if (rejime == "decode") {
            cout << "Введите строку для расшифрования:"<<endl;
            cin.get(); getline(cin, stroka);
            int kluch;
            cout << "Введите ключ:"<<endl; cin >> kluch;
            Shifr rashifr(kluch);
            wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
            wstring wstrdec = codec.from_bytes(stroka);
            cout<<codec.to_bytes(rashifr.decshifr(rashifr,wstrdec))<<endl;
        }       
if (rejime == "exit") {
            cout << "Завершение работы программы. Всего вам самого наилучшего!" << endl;
            vihod = false;
            break;
        }
    } while (vihod != false);
    return 0;
}
