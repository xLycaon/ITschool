#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>



using namespace std;

class Student {
private:
    string name;
    int matrikelnummer;
    vector<int> noten;
    double mittelNote;

public:
    Student(string n, int m, vector<int> grades) : name(n), matrikelnummer(m), noten(grades) {
        double sum = 0;
        for (int note : noten) {
            sum += note;
        }
        mittelNote = sum / noten.size();
    }

    string getName() const{
        return name;
    }

    int get1Note() const {
        return noten.at(0);
    }

    void set1Note(int number) {
        this->noten.at(0) = number;
    }

    int getMatrikelnummer() const {
        return matrikelnummer;
    }

    void print() const {
        cout << "Name: " << name << ", Matrikelnummer: " << matrikelnummer
            << ", Mittelnote: " << mittelNote << endl;
    }
    void printNoten() const {
        cout << "Name: " << name;
        for (const auto& note : noten) {
            cout <<" "<< note << " ";
        }
        cout << endl;
    }

    double getMittelNote() const {
        return mittelNote;
    }

};

vector<Student> readStudentsFromFile(const string& filename) {
    ifstream file(filename);
    vector<Student> studenten;
    if (!file) {
        cerr << "Datei konnte nicht geöffnet werden!" << endl;
        return studenten;
    }

    int anzahl;
    file >> anzahl;
    file.ignore(); 

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string name;
        int matrikelnummer;
        vector<int> noten(5);
        ss >> name >> matrikelnummer;
        for (int& note : noten) {
            ss >> note;
        }
        studenten.push_back(Student(name, matrikelnummer, noten));
       
    }

    return studenten;
}

vector<Student> erhohtNote(vector<Student>& studenten) {
    for (auto& student : studenten) {
        if (student.get1Note() < 10) {
            int currentNote = student.get1Note();
            student.set1Note(student.get1Note() + 1);
        }
    }
    return studenten;
}


bool compareByMittelNote(const Student& a, const Student& b) {
    return a.getMittelNote() > b.getMittelNote(); 
}

int main() {
    vector<Student> studenten = readStudentsFromFile("student.txt");
    vector<Student> studenten1 = studenten;

    cout << "Bevor Sortierung: " << endl << endl;

    for(const auto& student : studenten) {
        student.print();
    }
    cout << "------------------------------------" << endl;
    
    sort(studenten.begin(), studenten.end(), compareByMittelNote);

    cout << "Sortierte Studenten Daten:" << endl << endl;
    for (const auto& student : studenten) {
        student.print();
    }

    
    ofstream outFile("sort_studenten.txt");
    for (const auto& student : studenten) {
        outFile << student.getName() << " "
            << student.getMatrikelnummer() << " "
            << student.getMittelNote() << endl;
    }
    outFile.close();
    cout << "------------------------------------" << endl;
    //Testen 3 Funktionen
    studenten.erase(studenten.begin(), studenten.begin()+1); //loscht ersten Element
    cout << "Nach erase Funktion des ersten Element: " << endl << endl;
    for (const auto& student : studenten) {
        student.print();
    }
    studenten.pop_back();//loscht letzten element
    cout << "------------------------------------" << endl;
    cout << "Nach pop Funktion: " << endl << endl;
    for (const auto& student : studenten) {
        student.print();
    }

    cout << "------------------------------------" << endl;
    cout << "Nach clear Funktion: " << endl << endl;
    studenten.clear();
    for (const auto& student : studenten) {
        student.print();
    }
    cout << "------------------------------------" << endl;
    cout << "Augabe 2: " << endl << endl;
    cout << "Bevor Erhohung: " << endl;
    for (const auto& student : studenten1) {
        student.printNoten();
    }
    cout << "---------------------------------------";
    cout << "Nach Erhohung: " << endl;
    studenten1=erhohtNote(studenten1);
    for (const auto& student : studenten1) {
        student.printNoten();
    }
    


    return 0;
}