 #include <iostream> // for cin and cout
 #include <cstring> // for strcpy()
 #include <windows.h> // for SetConsoleTextAttribute()
 #include <conio.h> // for system()

 using namespace std;

 int x, y, z; // three keys
 string text;

 int main()
 {
    HANDLE hConsole;
    hConsole = GetStdHandle (STD_OUTPUT_HANDLE);
    cout << " MESSAGE ENCRYPTION\n Use only small (a-z) letters and dot (.)" << endl;
    cout << " _____________\n Enter key x: ";
    cin >> x;
    cout << " Enter key y: ";
    cin >> y;
    cout << " And key z: ";
    cin >> z;
    cout << "\n Write message to encrypt:" << endl;
    cin >> text;

    int n = text.size();

    char arrayoftext[n];
    strcpy(arrayoftext, text.c_str());

    int arrayofcodes[n];
    for(int i=0; i<n; i++){
        if(arrayoftext[i] == '.'){
            arrayofcodes[i] = 26;
        }
        else{
            arrayofcodes[i] = (int)arrayoftext[i] - 97; // 97 is a number of "a" in ASCII table
        }
    }

    for(int i=0; i<n; i++){
        int k = arrayofcodes[i];
        if(k < 0 || k > 26){
            cout << " You entered incorrect characters. Restart program and try again.";
            return 0;
        }
    }

    for(int i=0; i<=n; i+=2*z){
        for(int j=0; j<z; j++){
            arrayofcodes[i+j] += x;
        }
        for(int j=z; j<2*z; j++){
            arrayofcodes[i+j] += y;
        }
    }

    for(int k=0; k<n; k++){
        arrayofcodes[k] = (27+arrayofcodes[k])%27;
    }

    cout << "\n Cryptogram:" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
    for(int i=0; i<n; i++){
        if(arrayofcodes[i] == 26){
            arrayoftext[i] = '.';
        }
        else{
            arrayoftext[i] = (char)arrayofcodes[i] + 97;
        }

        cout << arrayoftext[i];

    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE );
    cout << "\n\n Copy this text with Ctrl+C.\n" << endl;
    system("PAUSE");
    return 0;
 }
