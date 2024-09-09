#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int menu()
{
    int choice;
    cout << "1- Print complex number " << endl;
    cout << "2- Add/ Subtract two complex numbers" << endl;
    cout << "3- Add/ Subtract a real number" << endl;
    cout << "4- Add/ Subtract an imaginary number" << endl;
    cout << "5- Comparison" << endl;
    cout << "6- Exit" << endl;
    cout << "Enter your choice:";
    cin >> choice;
    cin.ignore();
    return choice;
}

int menu2()
{
    int choice;
    cout << "1- Add" << endl << "2- Subtract" << endl;
    cout << "Enter your choice:";
    cin >> choice;
    cin.ignore();
    return choice;
}

class Complexnumber
{
private:
    double r;
    double img;
public:
    Complexnumber(int i = 1, int j = 1)
    {
        r = i;
        img = j;
    }
    void to_string() const
    {
        cout << r << " + " << img << "i" << endl;
    }

    Complexnumber operator+ (const Complexnumber& other) const
    {
        Complexnumber c;
        c.r = r + other.r;
        c.img = img + other.img;
        return c;
    }

    Complexnumber& operator+= (double n)
    {
        r += n;
        return *this;
    }

    Complexnumber& operator+= (int n)
    {
        img += n;
        return *this;
    }


    Complexnumber operator- (const Complexnumber& other) const
    {
        Complexnumber c;
        c.r = r - other.r;
        c.img = img - other.img;
        return c;
    }

    Complexnumber& operator-= (double n)
    {
        r -= n;
        return *this;
    }

    Complexnumber& operator-= (int n)
    {
        img -= n;
        return *this;
    }

    bool operator== (const Complexnumber& w) const
{
    if (r == w.r && img == w.img)
    {
        cout << "Both real and imaginary parts are equal." << endl;
        return true;
    }
    else
    {
        if (r == w.r)
        {
            cout << "The real part of the first number is equaled to the second one." << endl;
        }
        if (img == w.img)
        {
            cout << "The imaginary part of the first number is equaled to the second one." << endl;
        }
        return false; 
    }
}


    bool operator> (const Complexnumber& w) const
    {
        if (r > w.r)
        {
            cout << "The real part of the first number is greater than than second one." << endl;
            return true;
        }
        else if (r < w.r)
        {
            cout << "The real part of the first number is smaller than than second one." << endl;
            return true;
        }
         if (img > w.img)
        {
            cout << "The imaginary part of the first number is greater than the second one." << endl;
            return true;
         }
         else if (img < w.img)
         {
             cout << "The imaginary part of the first number is smaller than the second one." << endl;
             return true;
        }

         return false;
         
    }

    bool operator< (const Complexnumber& w) const
    {
        if (r < w.r)
        {
            cout << "The real part of the first number is smaller than second one." << endl;
            return true;
        }
        else if (r > w.r)
        {
            cout << "The real part of the first number is greater than second one." << endl;
            return true;
        }
        if (img < w.img)
        {
            cout << "The imaginary part of the first number is smaller than the second one." << endl;
            return true;
        }
        else if (img > w.img)
        {
            cout << "The imaginary part of the first number is greater than the second one." << endl;
            return true;
        }
        return false;
    }

    Complexnumber operator++()
    {
        ++r;
        ++img;
        return *this;
    }

    Complexnumber operator--()
    {
        --r;
        --img;
        return *this;
    }

    friend istream& operator>> (istream& input, Complexnumber& d);
};

istream& operator>> (istream& input, Complexnumber& d)
{
    cin >> d.r >> d.img;
    return input;
}


int main()
{
    while (true)
    {
        int choice = menu();

        if (choice == 1)
        {
            Complexnumber a;
            a.to_string();
            break;
        }
        else if (choice == 2)
        {
            Complexnumber a, b, c;
            cout << "Enter two complex numbers:" ;
            cin >> a;
            cin.ignore(); 
            cin >> b;
            cin.ignore();
            int choice1 = menu2();
            if (choice1 == 1)
            {
                c = a + b;
                c.to_string();
            }
            else
            {
                c = a - b;
                c.to_string();
            }
            break;
        }
        else if (choice == 3)
        {
            Complexnumber a;
            double num;
            int choice2 = menu2();
            cout << "Enter the number: ";
            cin >> num;
            cin.ignore();
            if (choice2 == 1)
            {
                if (num == 1) {
                    ++a;
                }
                else {
                    a += num;
                    a.to_string();
                }

            }
            else
            {
                if (num == 1) {
                    --a;
                }
                else {
                    a -= num;
                    a.to_string();
                }
            }
            break;
        }
        else if (choice == 4)
        {
            Complexnumber a;
            int choice3 = menu2();
            int num;
            cout << "Enter the number: ";
            cin >> num;
            cin.ignore();
            if (choice3 == 1)
            {
                a += num;
                a.to_string();
            }
            else
            {
                a -= num;
                a.to_string();
            }
            break;
        }
        else if (choice == 5)
        {
            Complexnumber a, b;
            cout << "Enter two complex numbers:";
            cin >> a;
            cin.ignore();
            cin >> b;
            cin.ignore();

            if (a == b)
            {
                cout << "The two complex numbers are equal in both real and imaginary parts." << endl;
            }
            else
            {
                if (a > b)
                {
                    cout << "The first number is greater than the second one." << endl;
                }
                else if (a < b)
                {
                    cout << "The second number is greater than the first one." << endl;
                }
            }
            break;
        }
        else if (choice == 6)
        {
            exit(0);
        }
        else
        {
            cout << "Invalid choice! Try again.\n";
        }
    }
    return 0;
}
