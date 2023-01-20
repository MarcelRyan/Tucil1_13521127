#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<time.h>

using namespace std;

int cekInputValidKartu(string input) {
    // Function untuk mengecek apakah input kartu valid atau tidak
    if (input == "A" || input == "Q" || input == "J" || input == "K" || input == "2" || input == "3" || input == "4" || input == "5" || input == "6" || input == "7" || input == "8" || input == "9" || input == "10") {
        return 1;
    }
    else  {
        return 0;
    }
}

double Operasi(double a, double b, char ops) {
    // Function untuk melakukan operasi penjumlahan, pengurangan, perkalian, dan pembagian
    if (ops == '+') {
        return a + b;
    }
    else if (ops == '-') {
        return a-b;
    }
    else if (ops == '*') {
        return a*b;
    }
    else if (ops == '/') {
        return a/b;
    }
}

int ubahNilai(char input) {
    // Function untuk mengubah nilai input menjadi angka apabila input berupa A J Q K
    if (input == 'A') {
        return 1;
    }
    else if (input == 'J') {
        return 11;
    }
    else if (input == 'Q') {
        return 12;
    }
    else if (input == 'K') {
        return 13;
    }
    else if (input == 'L') {
        return 10;
    }
    return input-'0';
}

string ubahKartu(char input) {
    // Function untuk mengubah kartu A J Q K menjadi string angka
    if (input == 'A') {
        return "1";
    }
    else if (input == 'J') {
        return "11";
    }
    else if (input == 'Q') {
        return "12";
    }
    else if (input == 'K') {
        return "13";
    }
    else if (input == 'L') {
        return "10";
    }
    else {
        string temp(1, input);
        return temp;
    }
}

string ubahNilaitoString(string input) {
    // Function untuk mengubah angka 11 12 13 10 dan 1 menjadi huruf J Q K L dan A
    if (input == "1") {
        return "A";
    }
    else if (input == "10") {
        return "L";
    }
    else if (input == "11") {
        return "J";
    }
    else if (input == "12") {
        return "Q";
    }
    else if (input == "13") {
        return "K";
    }
    else {
        return input;
    }
}

bool isInVector(vector <string> solusi, string kalimat) {
    // Function untuk mengecek apakah solusi sudah masuk ke dalam array
    for (string i : solusi) {
        if (i == kalimat) {
            return true;
        }
    }
    return false;
}

int main() {
    // Container
    vector <string> number;
    string ops[4] = {"+", "-", "*", "/"};

    // Menu awal
    string lanjut = "y";
    while (lanjut == "y") {
        // ASCII ART
        cout << R"(
                                                                                                    
                      ,--,                                                                          
      ,----,        ,--.'|          .--.--.               ,--,                                      
    .'   .' \    ,--,  | :         /  /    '.           ,--.'|                                      
  ,----,'    |,---.'|  : '        |  :  /`. /    ,---.  |  | :                       __  ,-.        
  |    :  .  ;;   : |  | ;        ;  |  |--`    '   ,'\ :  : '       .---.         ,' ,'/ /|        
  ;    |.'  / |   | : _' |        |  :  ;_     /   /   ||  ' |     /.  ./|  ,---.  '  | |' |        
  `----'/  ;  :   : |.'  |         \  \    `. .   ; ,. :'  | |   .-' . ' | /     \ |  |   ,'        
    /  ;  /   |   ' '  ; :          `----.   \'   | |: :|  | :  /___/ \: |/    /  |'  :  /          
   ;  /  /-,  \   \  .'. |          __ \  \  |'   | .; :'  : |__.   \  ' .    ' / ||  | '           
  /  /  /.`|   `---`:  | '         /  /`--'  /|   :    ||  | '.'|\   \   '   ;   /|;  : |           
./__;      :        '  ; |        '--'.     /  \   \  / ;  :    ; \   \  '   |  / ||  , ;           
|   :    .'         |  : ;          `--'---'    `----'  |  ,   /   \   \ |   :    | ---'            
;   | .'            '  ,/                                ---`-'     '---" \   \  /                  
`---'               '--'                                                   `----'                   
                                                                                                    
)" << endl;
        cout << "Selamat datang di program 24 Solver" << endl;
        cout << "Berikut beberapa pilihan yang terdapat pada program ini :" << endl;
        cout << "1. Nilai-Nilai Kartu akan digenerate secara random" << endl;
        cout << "2. Nilai-nilai kartu di input sendiri" << endl;
        cout << "Silahkan input pilihan Anda : ";
        string pilihan;
        cin >> pilihan;
        while (pilihan != "1" && pilihan != "2") {
            cout << "Pilihan tidak sesuai, silahkan masukan pilihan berupa angka 1 atau 2" << endl;
            cout << "Silahkan input pilihan Anda : ";
            cin >> pilihan;
        }
        if (pilihan == "1") {
            srand(time(NULL));
            int number1 = (rand() % 13) + 1;
            int number2 = (rand() % 13) + 1;
            int number3 = (rand() % 13) + 1;
            int number4 = (rand() % 13) + 1;

            cout << "Berikut bilangan-bilangan yang didapat :" << endl;
            cout << number1 << " " << number2 << " " << number3 << " " << number4 << endl;
            string numberbaru1 = to_string(number1);
            string numberbaru2 = to_string(number2);
            string numberbaru3 = to_string(number3);
            string numberbaru4 = to_string(number4);
            numberbaru1 = ubahNilaitoString(numberbaru1);
            numberbaru2 = ubahNilaitoString(numberbaru2);
            numberbaru3 = ubahNilaitoString(numberbaru3);
            numberbaru4 = ubahNilaitoString(numberbaru4);
            number.push_back(numberbaru1);
            number.push_back(numberbaru2);
            number.push_back(numberbaru3);
            number.push_back(numberbaru4);
        }
        else if (pilihan == "2") {
            // Input nilai-nilai kartu
            /* Note penting pada program ini diasumsikan input selalu berupa value kartu yang valid sehingga input 1 11 12 dan 13 bukan
             input yang valid dikarenakan pada kartu remi tidak ada kartu dengan angka 1 11 12 dan 13 melainkan hanya ada A J Q K */
            bool valid = false;
            cout << "Silahkan Masukan Nilai Kartu : ";
            cin.ignore();
            while (!valid) {
                string input = "";
                getline(cin, input);
                int n = 0;
                while (n < input.length()) {
                    if (input[n] == '1' && input[n+1] == '0' && n < input.length()-1) {
                        number.push_back("10");
                        n++;
                    }
                    else if (input[n] != ' ') {
                        string temp(1, input[n]);
                        number.push_back(temp);
                    }
                    n++;
                }
                if (number.size() != 4 && number.size() > 4) {
                    number.clear();
                    cout << "Input tidak valid, Silahkan masukan input sebanyak 4 string saja dan berupa angka 1-10 atau huruf A J Q K saja" << endl;
                    cout << "Silahkan Masukan Nilai Kartu : ";
                }
                else if (number.size() == 4) {
                    if ((cekInputValidKartu(number[0]) == 0 || cekInputValidKartu(number[1]) == 0 || cekInputValidKartu(number[3]) == 0 || cekInputValidKartu(number[2]) == 0)) {
                        cout << "Input tidak valid, Silahkan masukan input sebanyak 4 string saja dan berupa angka 1-10 atau huruf A J Q K saja" << endl;
                        cout << "Silahkan Masukan Nilai Kartu : ";
                        number.clear();
                    }
                    else {
                        valid = true;
                    }
                }
            }
        }

        clock_t start = clock();
        // Semua kemungkinan susunan angka dan operator
        vector <string> susunanAngka;
        // Apabila tidak ada angka yang sama
        for (int i = 0; i < 4 ; i++) {
            for (int j = 0; j < 4 ; j++) {
                for (int k = 0; k < 4 ; k++) {
                    for (int l = 0; l < 4 ; l++) {
                        if (i == j || i == k || i == l || j == k || j == l || k == l) {
                            continue;
                        }
                        string kombinasi = number[i] + number[j] + number[k] + number[l];
                        susunanAngka.push_back(kombinasi);
                    }
                }
            }
        }

        // Kasus khusus apabila semua angka sama
        if (number[0] == number[1] && number[0] == number[2] && number[0] == number[3]) {
            string kombinasi = number[0] + number[1] + number[2] + number[3];
            susunanAngka.push_back(kombinasi);
        }

        int index = 0;
        for (string i : susunanAngka) {
            for (int j = 0; j < i.length()-1; j++) {
                if (i[j] == '1' && i[j+1] == '0') {
                    i.erase(j, 2);
                    i.insert(j, "L");
                }
            }
            susunanAngka[index] = i;
            index++;
        }

        vector <string> susunanOperator;
        for (string i : ops) {
            for (string j : ops) {
                for (string k : ops) {
                    string kombinasiops = i + j + k;
                    susunanOperator.push_back(kombinasiops);
                }
            }
        }

        /* Looping untuk kombinasi semua tanda kurung
        Semua variasi dari tanda kurung adalah 1. (a op b) op (c op d)
                                            2. a op ((b op c) op d)
                                            3. a op (b op (c op d))
                                            4. ((a op b) op c) op d
                                            5. (a op (b op c)) op d */

        // Penampung solusi
        vector <string> seluruhSolusi;                                   
        for (string susunan : susunanAngka) {
            for (int i = 0; i < 5; i++) { //looping untuk semua kombinasi tanda kurung
                if (i == 0) {
                    for (string susunanop : susunanOperator) {
                        // Mengubah terlebih dahulu tipe data char menjadi string agar bisa di konkat
                        string temp1 = ubahKartu(susunan[0]); string temp2 = ubahKartu(susunan[1]); string temp3 = ubahKartu(susunan[2]); string temp4 = ubahKartu(susunan[3]); string temp5(1, susunanop[0]); string temp6(1, susunanop[1]); string temp7(1, susunanop[2]);
                        string solusi = "( " + temp1 + " " + temp5 + " " + temp2 + " ) " + temp6 + " " + "( " + temp3 + " " + temp7 + " " + temp4 + " )";
                        int angka1 = ubahNilai(susunan[0]);
                        int angka2 = ubahNilai(susunan[1]);
                        int angka3 = ubahNilai(susunan[2]);
                        int angka4 = ubahNilai(susunan[3]);
                        double hasil = Operasi(1.0*angka1, 1.0*angka2, susunanop[0]);
                        double hasil2 = Operasi(1.0*angka3, 1.0*angka4, susunanop[2]);
                        if (hasil2 == 0 && susunanop[1] == '/') {
                            continue;
                        }
                        double hasilakhir = Operasi(hasil, hasil2, susunanop[1]);
                        if (hasilakhir == 24.0 && !isInVector(seluruhSolusi, solusi)) {
                            seluruhSolusi.push_back(solusi);
                        }
                    }
                }
                if (i == 1) {
                    for (string susunanop : susunanOperator) {
                        // Mengubah terlebih dahulu tipe data char menjadi string agar bisa di konkat
                        string temp1 = ubahKartu(susunan[0]); string temp2 = ubahKartu(susunan[1]); string temp3 = ubahKartu(susunan[2]); string temp4 = ubahKartu(susunan[3]); string temp5(1, susunanop[0]); string temp6(1, susunanop[1]); string temp7(1, susunanop[2]);
                        string solusi = temp1 + " " + temp5 + " (( " + temp2 + " " + temp6 + " " + temp3 + " ) " + temp7 + " " + temp4 + " )";
                        int angka1 = ubahNilai(susunan[0]);
                        int angka2 = ubahNilai(susunan[1]);
                        int angka3 = ubahNilai(susunan[2]);
                        int angka4 = ubahNilai(susunan[3]);
                        double hasil = Operasi(1.0*angka2, 1.0*angka3, susunanop[1]);
                        double hasil2 = Operasi(hasil, 1.0*angka4, susunanop[2]);
                        if (hasil2 == 0 && susunanop[0] == '/') {
                            continue;
                        }
                        double hasilakhir = Operasi(1.0*angka1, hasil2, susunanop[0]);
                        if (hasilakhir == 24.0 && !isInVector(seluruhSolusi, solusi)) {
                            seluruhSolusi.push_back(solusi);
                        }  
                    }
                }
                if (i == 2) {
                    for (string susunanop : susunanOperator) {
                        // Mengubah terlebih dahulu tipe data char menjadi string agar bisa di konkat
                        string temp1 = ubahKartu(susunan[0]); string temp2 = ubahKartu(susunan[1]); string temp3 = ubahKartu(susunan[2]); string temp4 = ubahKartu(susunan[3]); string temp5(1, susunanop[0]); string temp6(1, susunanop[1]); string temp7(1, susunanop[2]);
                        string solusi = temp1 + " " + temp5 + " ( " + temp2 + " " + temp6 + " ( " + temp3 + " " + temp7 + " " + temp4 + " ))";
                        int angka1 = ubahNilai(susunan[0]);
                        int angka2 = ubahNilai(susunan[1]);
                        int angka3 = ubahNilai(susunan[2]);
                        int angka4 = ubahNilai(susunan[3]);
                        double hasil = Operasi(1.0*angka3, 1.0*angka4, susunanop[2]);
                        if (hasil == 0 && susunanop[1] == '/') {
                            continue;
                        }
                        double hasil2 = Operasi(1.0*angka2, hasil, susunanop[1]);
                        if (hasil2 == 0 && susunanop[0] == '/') {
                            continue;
                        }
                        double hasilakhir = Operasi(1.0*angka1, hasil2, susunanop[0]);
                        if (hasilakhir == 24.0 && !isInVector(seluruhSolusi, solusi)) {
                            seluruhSolusi.push_back(solusi);
                        } 
                    }
                }
                if (i == 3) {
                    for (string susunanop : susunanOperator) {
                        // Mengubah terlebih dahulu tipe data char menjadi string agar bisa di konkat
                        string temp1 = ubahKartu(susunan[0]); string temp2 = ubahKartu(susunan[1]); string temp3 = ubahKartu(susunan[2]); string temp4 = ubahKartu(susunan[3]); string temp5(1, susunanop[0]); string temp6(1, susunanop[1]); string temp7(1, susunanop[2]);
                        string solusi = "(( " + temp1 + " " + temp5 + " " + temp2 + " ) " + temp6 + " " + temp3 + " ) " + temp7 + " " + temp4;
                        int angka1 = ubahNilai(susunan[0]);
                        int angka2 = ubahNilai(susunan[1]);
                        int angka3 = ubahNilai(susunan[2]);
                        int angka4 = ubahNilai(susunan[3]);
                        double hasil = Operasi(1.0*angka1, 1.0*angka2, susunanop[0]);
                        double hasil2 = Operasi(hasil, 1.0*angka3, susunanop[1]);
                        double hasilakhir = Operasi(hasil2, 1.0*angka4, susunanop[2]);
                        if (hasilakhir == 24.0 && !isInVector(seluruhSolusi, solusi)) {
                            seluruhSolusi.push_back(solusi);
                        }
                    }
                }
                if (i == 4) {
                    for (string susunanop : susunanOperator) {
                        // Mengubah terlebih dahulu tipe data char menjadi string agar bisa di konkat
                        string temp1 = ubahKartu(susunan[0]); string temp2 = ubahKartu(susunan[1]); string temp3 = ubahKartu(susunan[2]); string temp4 = ubahKartu(susunan[3]); string temp5(1, susunanop[0]); string temp6(1, susunanop[1]); string temp7(1, susunanop[2]);
                        string solusi = "( " + temp1 + " " + temp5 + " ( " + temp2 + " " + temp6 + " " + temp3 + " )) " + temp7 + " " + temp4;
                        int angka1 = ubahNilai(susunan[0]);
                        int angka2 = ubahNilai(susunan[1]);
                        int angka3 = ubahNilai(susunan[2]);
                        int angka4 = ubahNilai(susunan[3]);
                        double hasil = Operasi(1.0*angka2, 1.0*angka3, susunanop[1]);
                        if (hasil == 0 && susunanop[0] == '/') {
                            continue;
                        }
                        double hasil2 = Operasi(1.0*angka1, hasil, susunanop[0]);
                        double hasilakhir = Operasi(hasil2, 1.0*angka4, susunanop[2]);
                        if (hasilakhir == 24.0 && !isInVector(seluruhSolusi, solusi)) {
                            seluruhSolusi.push_back(solusi);
                        }
                    }
                }
            }
        }

        // Print semua solusi
        if (seluruhSolusi.size() == 0) {
            cout << "Tidak ada solusi untuk kombinasi kartu ini" << endl;
            clock_t end = clock();
            cout << "Waktu eksekusi program adalah " << end-start << " milliseconds" << endl;
        } 
        else {
            cout << "Berikut adalah seluruh solusi untuk kombinasi kartu ini" << endl;
            for (string i : seluruhSolusi) {
                cout << i << endl;
            }
            cout << "Ada " << seluruhSolusi.size() << " untuk kombinasi kartu ini" << endl;
            clock_t end = clock();
            cout << "Waktu eksekusi program adalah " << end-start << " milliseconds" << endl;

            // Bagian pemrosesan save file
            string inginsave = "";
            cout << "Apakah ingin menyimpan solusi ke dalam sebuah file txt? (ketik y atau Y jika ya dan n atau N jika tidak)" << endl;
            cin >> inginsave;
            while (inginsave != "y" && inginsave != "Y" && inginsave != "N" && inginsave != "n") {
                cout << "Input tidak valid silahkan input y atau Y apabila ingin menyimpan solusi ke dalam sebuah file txt dan n atau N jika tidak" << endl;
                cin >> inginsave;
            }
            if (inginsave == "y" || inginsave == "Y") {
                cout << "Input nama file tanpa menggunakan .txt di nama file" << endl;
                string namafile;
                cin >> namafile;
                namafile += ".txt";
                ofstream filesave;
                filesave.open(namafile.c_str());
                for (string i : seluruhSolusi) {
                    filesave << i << "\n";
                }
                filesave.close();
            }
        }

        cout << "Apakah masih ingin menggunakan program ini jika ya ketik y dan jika tidak ketik n" << endl;
        cin >> lanjut;
        if (lanjut == "n" || lanjut == "N") {
            cout << "Terima kasih telah menggunakan program 24 Solver ini" << endl;
        }
        else if (lanjut == "y" || lanjut == "Y") {
            number.clear();
        }
    }
}