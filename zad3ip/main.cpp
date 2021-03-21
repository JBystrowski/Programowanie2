//Bystrowski Jakub
#include <iostream>

using namespace std;

struct Adres
{
    int first;
    int second;
    int third;
    int fourth;

    void display(){
        cout << first << "." << second << "." << third << "." << fourth;
    }
};


bool isGood(string ip, Adres* res){
    int fragment = 0;
    int count = 0;
    for(int i = 0; i < ip.size(); ++i){
        if((ip[i] >= '0') && (ip[i] <= '9')){
            fragment *= 10;
            fragment += ip[i] - '0';
        }else{
            if(ip[i] == '.'){
                if(fragment > 255) return false;

                switch (count)
                {
                case 0:
                    res->first = fragment;
                    break;
                    
                case 1:
                    res->second = fragment;
                    break;

                case 2:
                    res->third = fragment;
                    break;

                default:
                    return false;
                    break;
                }
            }else{
                return false;
            }
        }
    }
    if((count == 3) && (fragment <= 255)){
        res->fourth = fragment;
        return true;
    }
    return false;
}

int main()
{
    string s;
    Adres ip;
    Adres mask;

    cout << "Podaj adres IPv4" <<endl;
    cin >> s;
    while(!isGood(s,&ip)){
        cout << "Niepoprawny adres IPv4 podaj ponownie" <<endl;
        cin >> s;
    }

    cout << "Podaj maske" <<endl;
    cin >> s;
    while(!isGood(s,&mask)){
        cout << "Nieprawidłowa maska podaj ponwnie" <<endl;
        cin >> s;
    }

    

    return 0;
}