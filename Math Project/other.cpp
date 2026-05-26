#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S, s, str;
    cout << "Enter the equation (e.g., ax^2 + by^2 + cxy + dx + ey + f = 0): ";
    getline(cin, S);

    for(char ch : S)
        if(ch != ' ')
            s.push_back(tolower(ch));

    map<char, string> m;
    m.insert({'a', "0"});
    m.insert({'b', "0"});
    m.insert({'c', "0"});
    m.insert({'d', "0"});
    m.insert({'e', "0"});
    m.insert({'f', "0"});
    m.insert({'F', "0"});

    for(int i = 0; i<s.size(); i++)
    {
        if(s[i] == 'x')
        {
            if(str == "" || str == "-")
                str.push_back('1');

            if(s[i+1] == '^' || s[i+2] == '2')
            {
                m['a'] = str;
                i += 2;
            }

            else if(s[i+1] == 'y')
            {
                m['c'] = str;
                i++;
            }

            else
                m['d'] = str;

            str = "";
        }

        else if(s[i] == 'y')
        {
            if(str == "" || str == "-")
                str.push_back('1');

            if(s[i+1] == '^' || s[i+2] == '2')
            {
                m['b'] = str;
                i += 2;
            }
            else
                m['e'] = str;

            str = "";
        }

        else if(s[i] == '=')
        {
            if(str != "-" && str != "")
                m['f'] = str;

            str = "";
        }

        else if((s[i] >= '0' && s[i] <= '9') || s[i] == '-')
            str.push_back(s[i]);
    }

    m['F'] = str;

    double a = stod(m['a']);
    double h = stod(m['c']) / 2;
    double b = stod(m['b']);
    double g = stod(m['d']) / 2;
    double f = stod(m['e']) / 2;
    double c = stod(m['f']) + stod(m['F']);

    double D = a*(b*c - f*f) - h*(h*c - f*g) + g*(h*f - b*g);
    double d = h*h - a*b;
    double t = g*g + f*f - c;
    double T = h + g + f + c;

    if(a == b && T == 0)
        cout << "It is a circle with radius zero and origin (0, 0)" << endl;

    else if(D == 0)
        cout << "Pair of Straight line" << endl;

    else if(a == b && a != 0 && t >= 0)
        cout << "Circle" << endl;

    else if(d < 0)
        cout << "Ellipse" << endl;

    else if(d > 0)
        cout << "Hyperbola" << endl;
    else if(d == 0)
        cout << "Parabola" << endl;

    main();
}