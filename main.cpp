#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

void existing_customer_or_not();
void not_a_customer();
void existing_customer();
void display_platform();
// language class
class Language
{
protected:
    int language[100];
    char lang_ref[100];
    string s1;
    int l;

public:
    void display_language();
    void language_selection();
    void string_array_conv_language(string str);
    void change_language();
};

void Language ::display_language()
{
    fstream FileName;
    FileName.open("Select_languages.txt", ios::in);
    string st;
    while (FileName.eof() == 0)
    {
        getline(FileName, st);
        cout << st << endl;
    }
    FileName.close();
}

void Language ::language_selection()
{
    cout << "Enter a number to select languages" << endl;
    fflush(stdin);
    getline(cin, s1);
    string_array_conv_language(s1);
}

void Language ::string_array_conv_language(string str)
{
    int str_length = str.length();
    int i;
    l = -1;
    for (i = 0; i < str_length; i++)
    {
        if (str[i] == ' ')
        {
        }

        else
        {
            l++;
            language[l] = str[i] - 48;

            if (language[l] < 1 || language[l] > 5)
            {
                cout << "Please enter the correct input" << endl;
                display_language();
                language_selection();
                return;
            }
        }
    }

    for (i = 0; i <= l; i++) // stores the input numbers in an ascending order
    {
        for (int k = i + 1; k <= l; k++)
        {
            if (language[i] > language[k])
            {
                int temp = language[i];
                language[i] = language[k];
                language[k] = temp;
            }
        }
    }

    for (i = 0; i <= l; i++)
    {
        if (language[i] == 1)
        {
            lang_ref[i] = 'E';
        }
        else if (language[i] == 2)
        {
            lang_ref[i] = 'H';
        }
        else if (language[i] == 3)
        {
            lang_ref[i] = 'T';
        }
        else if (language[i] == 4)
        {
            lang_ref[i] = 'K';
        }
        else if (language[i] == 5)
        {
            lang_ref[i] = 'P';
        }
    }

    cout << "Selected languages:" << endl; // displays the selected languages
    for (i = 0; i <= l; i++)
    {
        cout << language[i] << " ";
    }
    cout << endl;
    change_language();
    system("cls");
}

void Language ::change_language()
{
    cout << "Do you want to change your options?" << endl
         << "1. Yes" << endl
         << "2. No" << endl;
    int change;
    cin >> change;
    if (change == 1)
    {
        system("cls");
        display_language();
        language_selection();
    }
    else if (change == 2)
    {
        return;
    }
    else
    {
        cout << "Please enter correct input" << endl;
        change_language();
    }
}

// genre class
class Genre
{
protected:
    int genre[100];
    string s2;
    int g;

public:
    void display_genre();
    void genre_selection();
    void string_array_conv_genre(string str);
    void change_genre();
};

void Genre ::display_genre()
{
    fstream FileName;
    FileName.open("Select_genre.txt", ios::in);
    string st;
    while (FileName.eof() == 0)
    {
        getline(FileName, st);
        cout << st << endl;
    }
    FileName.close();
}

void Genre ::genre_selection()
{
    cout << "Enter a number to select genres" << endl;
    fflush(stdin);
    getline(cin, s2);
    string_array_conv_genre(s2);
}

void Genre ::string_array_conv_genre(string str)
{
    int str_length = str.length();
    int i;
    g = -1;

    for (i = 0; i < str_length; i++)
    {
        if (str[i] == ' ')
        {
        }

        else
        {
            g++;
            genre[g] = str[i] - 48;

            if (i + 1 < str_length && str[i + 1] != ' ')
            {
                int gen;
                gen = str[i + 1] - 48;
                genre[g] = genre[g] * 10 + gen;
                i++;
            }

            if (genre[g] < 1 || genre[g] > 7)
            {
                cout << "Please enter the correct input" << endl;
                display_genre();
                genre_selection();
                return;
            }
        }
    }

    for (i = 0; i <= g; i++)
    { // arranging the input numbers in an ascending order
        for (int k = i + 1; k <= g; k++)
        {
            if (genre[i] > genre[k])
            {
                int temp = genre[i];
                genre[i] = genre[k];
                genre[k] = temp;
            }
        }
    }

    cout << "Selected genres:" << endl;
    for (i = 0; i <= g; i++)
    {
        cout << genre[i] << " ";
    }
    cout << endl;
    change_genre();
    system("cls");
}

void Genre ::change_genre()
{
    cout << "Do you want to change your options?" << endl
         << "1. Yes" << endl
         << "2. No" << endl;
    int change;
    cin >> change;
    if (change == 1)
    {
        system("cls");
        display_genre();
        genre_selection();
    }
    else if (change == 2)
    {
        return;
    }
    else
    {
        cout << "Please enter correct input" << endl;
        change_genre();
    }
}

// channel class
class Channel : public Language, public Genre
{
protected:
    struct Cha
    {
        char channel_code;
        int channel_num;
    };
    Cha channel[200];
    int c;
    int channel_option;
    int free_channel_option;
    double total_price;
    string s3;

    friend class ExistingCustomer;

public:
    int channel_months;
    void display_channel();
    void channel_selection_options();
    void channel_selection();
    void select_all_channels_calculate_price();
    void string_array_conv_channels(string channel_str);
    bool channel_verification();
    void change_channel();
    void calculate_channel_price();
    void display_total_cost();
    void select_free_channels();
    void store_channels_in_structure_array();
};

void Channel ::display_channel()
{
    fstream FileName;
    FileName.open("Please_Select_Channels.txt", ios::in);
    string st;
    while (FileName.eof() == 0)
    {
        getline(FileName, st);
        cout << st << endl;
    }
    FileName.close();

    for (int i = 0; i <= l; i++)
    {
        for (int j = 0; j <= g; j++)
        {
            if (language[i] == 1 && genre[j] == 1)
            {
                FileName.open("English_TV_Shows.txt", ios::in);
                while (FileName.eof() == 0)
                {
                    getline(FileName, st);
                    cout << st << endl;
                }
                FileName.close();
            }

            if (language[i] == 1 && genre[j] == 2)
            {
                FileName.open("English_Movies.txt", ios::in);
                while (FileName.eof() == 0)
                {
                    getline(FileName, st);
                    cout << st << endl;
                }
                FileName.close();
            }

            if (language[i] == 1 && genre[j] == 3)
            {
                FileName.open("English_News.txt", ios::in);
                while (FileName.eof() == 0)
                {
                    getline(FileName, st);
                    cout << st << endl;
                }
                FileName.close();
            }

            if (language[i] == 1 && genre[j] == 4)
            {
                FileName.open("English_Sports.txt", ios::in);
                while (FileName.eof() == 0)
                {
                    getline(FileName, st);
                    cout << st << endl;
                }
                FileName.close();
            }

            if (language[i] == 1 && genre[j] == 5)
            {
                FileName.open("English_Music.txt", ios::in);
                while (FileName.eof() == 0)
                {
                    getline(FileName, st);
                    cout << st << endl;
                }
                FileName.close();
            }

            if (language[i] == 1 && genre[j] == 6)
            {
                FileName.open("English_Knowledge.txt", ios::in);
                while (FileName.eof() == 0)
                {
                    getline(FileName, st);
                    cout << st << endl;
                }
                FileName.close();
            }

            if (language[i] == 1 && genre[j] == 7)
            {
                FileName.open("English_Kids.txt", ios::in);
                while (FileName.eof() == 0)
                {
                    getline(FileName, st);
                    cout << st << endl;
                }
                FileName.close();
            }

            if (language[i] == 2 && genre[j] == 1)
            {
                FileName.open("Hindi_TV_Shows.txt", ios::in);
                while (FileName.eof() == 0)
                {
                    getline(FileName, st);
                    cout << st << endl;
                }
                FileName.close();
            }

            if (language[i] == 2 && genre[j] == 2)
            {
                FileName.open("Hindi_Movies.txt", ios::in);
                while (FileName.eof() == 0)
                {
                    getline(FileName, st);
                    cout << st << endl;
                }
                FileName.close();
            }

            if (language[i] == 2 && genre[j] == 3)
            {
                FileName.open("Hindi_News.txt", ios::in);
                while (FileName.eof() == 0)
                {
                    getline(FileName, st);
                    cout << st << endl;
                }
                FileName.close();
            }

            if (language[i] == 2 && genre[j] == 4)
            {
                FileName.open("Hindi_Sports.txt", ios::in);
                while (FileName.eof() == 0)
                {
                    getline(FileName, st);
                    cout << st << endl;
                }
                FileName.close();
            }

            if (language[i] == 2 && genre[j] == 5)
            {
                FileName.open("Hindi_Music.txt", ios::in);
                while (FileName.eof() == 0)
                {
                    getline(FileName, st);
                    cout << st << endl;
                }
                FileName.close();
            }

            if (language[i] == 2 && genre[j] == 6)
            {
                FileName.open("Hindi_Knowledge.txt", ios::in);
                while (FileName.eof() == 0)
                {
                    getline(FileName, st);
                    cout << st << endl;
                }
                FileName.close();
            }

            if (language[i] == 2 && genre[j] == 7)
            {
                FileName.open("Hindi_Kids.txt", ios::in);
                while (FileName.eof() == 0)
                {
                    getline(FileName, st);
                    cout << st << endl;
                }
                FileName.close();
            }

            if (language[i] == 3 && genre[j] == 1)
            {
                FileName.open("Telugu_TV_Shows.txt", ios::in);
                while (FileName.eof() == 0)
                {
                    getline(FileName, st);
                    cout << st << endl;
                }
                FileName.close();
            }

            if (language[i] == 3 && genre[j] == 2)
            {
                FileName.open("Telugu_Movies.txt", ios::in);
                while (FileName.eof() == 0)
                {
                    getline(FileName, st);
                    cout << st << endl;
                }
                FileName.close();
            }

            if (language[i] == 3 && genre[j] == 3)
            {
                FileName.open("Telugu_News.txt", ios::in);
                while (FileName.eof() == 0)
                {
                    getline(FileName, st);
                    cout << st << endl;
                }
                FileName.close();
            }

            if (language[i] == 3 && genre[j] == 4)
            {
                FileName.open("Telugu_Sports.txt", ios::in);
                while (FileName.eof() == 0)
                {
                    getline(FileName, st);
                    cout << st << endl;
                }
                FileName.close();
            }

            if (language[i] == 3 && genre[j] == 5)
            {
                FileName.open("Telugu_Music.txt", ios::in);
                while (FileName.eof() == 0)
                {
                    getline(FileName, st);
                    cout << st << endl;
                }
                FileName.close();
            }

            if (language[i] == 3 && genre[j] == 7)
            {
                FileName.open("Telugu_Kids.txt", ios::in);
                while (FileName.eof() == 0)
                {
                    getline(FileName, st);
                    cout << st << endl;
                }
                FileName.close();
            }

            if (language[i] == 4 && genre[j] == 1)
            {
                FileName.open("Kannada_TV_Shows.txt", ios::in);
                while (FileName.eof() == 0)
                {
                    getline(FileName, st);
                    cout << st << endl;
                }
                FileName.close();
            }

            if (language[i] == 4 && genre[j] == 2)
            {
                FileName.open("Kannada_Movies.txt", ios::in);
                while (FileName.eof() == 0)
                {
                    getline(FileName, st);
                    cout << st << endl;
                }
                FileName.close();
            }

            if (language[i] == 4 && genre[j] == 3)
            {
                FileName.open("Kannada_News.txt", ios::in);
                while (FileName.eof() == 0)
                {
                    getline(FileName, st);
                    cout << st << endl;
                }
                FileName.close();
            }

            if (language[i] == 4 && genre[j] == 4)
            {
                FileName.open("Kannada_Sports.txt", ios::in);
                while (FileName.eof() == 0)
                {
                    getline(FileName, st);
                    cout << st << endl;
                }
                FileName.close();
            }

            if (language[i] == 4 && genre[j] == 5)
            {
                FileName.open("Kannada_Music.txt", ios::in);
                while (FileName.eof() == 0)
                {
                    getline(FileName, st);
                    cout << st << endl;
                }
                FileName.close();
            }

            if (language[i] == 4 && genre[j] == 7)
            {
                FileName.open("Kannada_Kids.txt", ios::in);
                while (FileName.eof() == 0)
                {
                    getline(FileName, st);
                    cout << st << endl;
                }
                FileName.close();
            }

            if (language[i] == 5 && genre[j] == 1)
            {
                fstream FileName;
                FileName.open("Punjabi_TV_Shows.txt", ios::in);
                string st;
                while (FileName.eof() == 0)
                {
                    getline(FileName, st);
                    cout << st << endl;
                }
                FileName.close();
            }

            if (language[i] == 5 && genre[j] == 2)
            {
                FileName.open("Punjabi_Movies.txt", ios::in);
                while (FileName.eof() == 0)
                {
                    getline(FileName, st);
                    cout << st << endl;
                }
                FileName.close();
            }

            if (language[i] == 5 && genre[j] == 3)
            {
                FileName.open("Punjabi_News.txt", ios::in);
                while (FileName.eof() == 0)
                {
                    getline(FileName, st);
                    cout << st << endl;
                }
                FileName.close();
            }

            if (language[i] == 5 && genre[j] == 5)
            {
                FileName.open("Punjabi_Music.txt", ios::in);
                while (FileName.eof() == 0)
                {
                    getline(FileName, st);
                    cout << st << endl;
                }
                FileName.close();
            }
        }
    }
}

void Channel ::channel_selection_options()
{
    cout << "Please enter" << endl
         << "1. Select all channels" << endl
         << "2. Select channels" << endl;
    cin >> channel_option;
    if (channel_option == 1)
    {
        select_all_channels_calculate_price();
        store_channels_in_structure_array();
    }
    else if (channel_option == 2)
    {
        channel_selection();
    }
    else
    {
        cout << "Please enter a valid choice" << endl;
        channel_selection_options();
    }
}

void Channel ::channel_selection()
{
    cout << "Please select channels" << endl;
    fflush(stdin);
    getline(cin, s3);
    string_array_conv_channels(s3);
}

void Channel ::string_array_conv_channels(string str)
{
    int str_length = str.length();
    int i;
    c = -1;
    for (i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
        }
        else if ((str[i] > 64 && str[i] < 91))
        {
            c++;
            channel[c].channel_code = str[i];
        }
        else if ((str[i] > 96 && str[i] < 123))
        {
            c++;
            channel[c].channel_code = str[i] - 32;
        }
        else
        {
            channel[c].channel_num = str[i] - 48;

            if (i + 1 < str_length && str[i + 1] != ' ')
            {
                int chan;
                chan = str[i + 1] - 48;
                channel[c].channel_num = channel[c].channel_num * 10 + chan;
                i++;
            }
        }
    }

    if (channel_verification())
    {
        cout << "Selected channels" << endl;
        for (i = 0; i <= c; i++)
        {
            cout << channel[i].channel_code << channel[i].channel_num << " ";
        }
        cout << endl;
        calculate_channel_price();
        change_channel();
        system("cls");
    }
}

bool Channel ::channel_verification()
{
    int i;

    for (i = 0; i <= c; i++) // verification of channel_code
    {
        if ((channel[i].channel_code != 'E') && (channel[i].channel_code != 'H') && (channel[i].channel_code != 'T') && (channel[i].channel_code != 'K') && (channel[i].channel_code != 'P'))
        {
            cout << "Please enter the correct input" << endl;
            channel_selection();
            return false;
        }
    }

    for (i = 0; i <= c; i++)
    {
        int flag = 0;
        for (int j = 0; j <= l; j++)
        {
            if (channel[i].channel_code == lang_ref[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            cout << "Please enter the correct input" << endl;
            channel_selection();
            return false;
        }
    }

    for (i = 0; i <= c; i++) // verification of channel_num
    {
        if (channel[i].channel_code == 'E')
        {
            if (channel[i].channel_num > 0 && channel[i].channel_num < 5)
            {
                int flag1 = 0;
                for (int j = 0; j <= g; j++)
                {
                    if (genre[j] == 1)
                    {
                        flag1 = 1;
                        break;
                    }
                }
                if (flag1 == 0)
                {
                    cout << "Please enter the correct input" << endl;
                    channel_selection();
                    return false;
                }
            }

            else if (channel[i].channel_num > 4 && channel[i].channel_num < 13)
            {
                int flag2 = 0;
                for (int j = 0; j <= g; j++)
                {
                    if (genre[j] == 2)
                    {
                        flag2 = 1;
                        break;
                    }
                }
                if (flag2 == 0)
                {
                    cout << "Please enter the correct input" << endl;
                    channel_selection();
                    return false;
                }
            }

            else if (channel[i].channel_num > 12 && channel[i].channel_num < 22)
            {
                int flag3 = 0;
                for (int j = 0; j <= g; j++)
                {
                    if (genre[j] == 3)
                    {
                        flag3 = 1;
                        break;
                    }
                }
                if (flag3 == 0)
                {
                    cout << "Please enter the correct input" << endl;
                    channel_selection();
                    return false;
                }
            }

            else if (channel[i].channel_num > 21 && channel[i].channel_num < 30)
            {
                int flag4 = 0;
                for (int j = 0; j <= g; j++)
                {
                    if (genre[j] == 4)
                    {
                        flag4 = 1;
                        break;
                    }
                }
                if (flag4 == 0)
                {
                    cout << "Please enter the correct input" << endl;
                    channel_selection();
                    return false;
                }
            }

            else if (channel[i].channel_num > 29 && channel[i].channel_num < 35)
            {
                int flag5 = 0;
                for (int j = 0; j <= g; j++)
                {
                    if (genre[j] == 5)
                    {
                        flag5 = 1;
                        break;
                    }
                }
                if (flag5 == 0)
                {
                    cout << "Please enter the correct input" << endl;
                    channel_selection();
                    return false;
                }
            }

            else if (channel[i].channel_num > 34 && channel[i].channel_num < 42)
            {
                int flag6 = 0;
                for (int j = 0; j <= g; j++)
                {
                    if (genre[j] == 6)
                    {
                        flag6 = 1;
                        break;
                    }
                }
                if (flag6 == 0)
                {
                    cout << "Please enter the correct input" << endl;
                    channel_selection();
                    return false;
                }
            }

            else if (channel[i].channel_num > 41 && channel[i].channel_num < 47)
            {
                int flag7 = 0;
                for (int j = 0; j <= g; j++)
                {
                    if (genre[j] == 7)
                    {
                        flag7 = 1;
                        break;
                    }
                }
                if (flag7 == 0)
                {
                    cout << "Please enter the correct input" << endl;
                    channel_selection();
                    return false;
                }
            }

            else
            {
                cout << "Please enter the correct input" << endl;
                channel_selection();
                return false;
            }
        }

        if (channel[i].channel_code == 'H')
        {
            if (channel[i].channel_num > 0 && channel[i].channel_num < 13)
            {
                int flag1 = 0;
                for (int j = 0; j <= g; j++)
                {
                    if (genre[j] == 1)
                    {
                        flag1 = 1;
                        break;
                    }
                }
                if (flag1 == 0)
                {
                    cout << "Please enter the correct input" << endl;
                    channel_selection();
                    return false;
                }
            }

            else if (channel[i].channel_num > 12 && channel[i].channel_num < 21)
            {
                int flag2 = 0;
                for (int j = 0; j <= g; j++)
                {
                    if (genre[j] == 2)
                    {
                        flag2 = 1;
                        break;
                    }
                }
                if (flag2 == 0)
                {
                    cout << "Please enter the correct input" << endl;
                    channel_selection();
                    return false;
                }
            }

            else if (channel[i].channel_num > 20 && channel[i].channel_num < 29)
            {
                int flag3 = 0;
                for (int j = 0; j <= g; j++)
                {
                    if (genre[j] == 3)
                    {
                        flag3 = 1;
                        break;
                    }
                }
                if (flag3 == 0)
                {
                    cout << "Please enter the correct input" << endl;
                    channel_selection();
                    return false;
                }
            }

            else if (channel[i].channel_num > 28 && channel[i].channel_num < 32)
            {
                int flag4 = 0;
                for (int j = 0; j <= g; j++)
                {
                    if (genre[j] == 4)
                    {
                        flag4 = 1;
                        break;
                    }
                }
                if (flag4 == 0)
                {
                    cout << "Please enter the correct input" << endl;
                    channel_selection();
                    return false;
                }
            }

            else if (channel[i].channel_num > 31 && channel[i].channel_num < 38)
            {
                int flag5 = 0;
                for (int j = 0; j <= g; j++)
                {
                    if (genre[j] == 5)
                    {
                        flag5 = 1;
                        break;
                    }
                }
                if (flag5 == 0)
                {
                    cout << "Please enter the correct input" << endl;
                    channel_selection();
                    return false;
                }
            }

            else if (channel[i].channel_num > 37 && channel[i].channel_num < 41)
            {
                int flag6 = 0;
                for (int j = 0; j <= g; j++)
                {
                    if (genre[j] == 6)
                    {
                        flag6 = 1;
                        break;
                    }
                }
                if (flag6 == 0)
                {
                    cout << "Please enter the correct input" << endl;
                    channel_selection();
                    return false;
                }
            }

            else if (channel[i].channel_num > 40 && channel[i].channel_num < 44)
            {
                int flag7 = 0;
                for (int j = 0; j <= g; j++)
                {
                    if (genre[j] == 7)
                    {
                        flag7 = 1;
                        break;
                    }
                }
                if (flag7 == 0)
                {
                    cout << "Please enter the correct input" << endl;
                    channel_selection();
                    return false;
                }
            }

            else
            {
                cout << "Please enter the correct input" << endl;
                channel_selection();
                return false;
            }
        }

        if (channel[i].channel_code == 'T')
        {
            if (channel[i].channel_num > 0 && channel[i].channel_num < 8)
            {
                int flag1 = 0;
                for (int j = 0; j <= g; j++)
                {
                    if (genre[j] == 1)
                    {
                        flag1 = 1;
                        break;
                    }
                }
                if (flag1 == 0)
                {
                    cout << "Please enter the correct input" << endl;
                    channel_selection();
                    return false;
                }
            }

            else if (channel[i].channel_num > 7 && channel[i].channel_num < 13)
            {
                int flag2 = 0;
                for (int j = 0; j <= g; j++)
                {
                    if (genre[j] == 2)
                    {
                        flag2 = 1;
                        break;
                    }
                }
                if (flag2 == 0)
                {
                    cout << "Please enter the correct input" << endl;
                    channel_selection();
                    return false;
                }
            }

            else if (channel[i].channel_num > 12 && channel[i].channel_num < 21)
            {
                int flag3 = 0;
                for (int j = 0; j <= g; j++)
                {
                    if (genre[j] == 3)
                    {
                        flag3 = 1;
                        break;
                    }
                }
                if (flag3 == 0)
                {
                    cout << "Please enter the correct input" << endl;
                    channel_selection();
                    return false;
                }
            }

            else if (channel[i].channel_num > 20 && channel[i].channel_num < 23)
            {
                int flag4 = 0;
                for (int j = 0; j <= g; j++)
                {
                    if (genre[j] == 4)
                    {
                        flag4 = 1;
                        break;
                    }
                }
                if (flag4 == 0)
                {
                    cout << "Please enter the correct input" << endl;
                    channel_selection();
                    return false;
                }
            }

            else if (channel[i].channel_num > 22 && channel[i].channel_num < 26)
            {
                int flag5 = 0;
                for (int j = 0; j <= g; j++)
                {
                    if (genre[j] == 5)
                    {
                        flag5 = 1;
                        break;
                    }
                }
                if (flag5 == 0)
                {
                    cout << "Please enter the correct input" << endl;
                    channel_selection();
                    return false;
                }
            }

            else if (channel[i].channel_num > 25 && channel[i].channel_num < 29)
            {
                int flag7 = 0;
                for (int j = 0; j <= g; j++)
                {
                    if (genre[j] == 7)
                    {
                        flag7 = 1;
                        break;
                    }
                }
                if (flag7 == 0)
                {
                    cout << "Please enter the correct input" << endl;
                    channel_selection();
                    return false;
                }
            }

            else
            {
                cout << "Please enter the correct input" << endl;
                channel_selection();
                return false;
            }
        }

        if (channel[i].channel_code == 'K')
        {
            if (channel[i].channel_num > 0 && channel[i].channel_num < 7)
            {
                int flag1 = 0;
                for (int j = 0; j <= g; j++)
                {
                    if (genre[j] == 1)
                    {
                        flag1 = 1;
                        break;
                    }
                }
                if (flag1 == 0)
                {
                    cout << "Please enter the correct input" << endl;
                    channel_selection();
                    return false;
                }
            }

            else if (channel[i].channel_num > 6 && channel[i].channel_num < 10)
            {
                int flag2 = 0;
                for (int j = 0; j <= g; j++)
                {
                    if (genre[j] == 2)
                    {
                        flag2 = 1;
                        break;
                    }
                }
                if (flag2 == 0)
                {
                    cout << "Please enter the correct input" << endl;
                    channel_selection();
                    return false;
                }
            }

            else if (channel[i].channel_num > 9 && channel[i].channel_num < 15)
            {
                int flag3 = 0;
                for (int j = 0; j <= g; j++)
                {
                    if (genre[j] == 3)
                    {
                        flag3 = 1;
                        break;
                    }
                }
                if (flag3 == 0)
                {
                    cout << "Please enter the correct input" << endl;
                    channel_selection();
                    return false;
                }
            }

            else if (channel[i].channel_num > 14 && channel[i].channel_num < 17)
            {
                int flag4 = 0;
                for (int j = 0; j <= g; j++)
                {
                    if (genre[j] == 4)
                    {
                        flag4 = 1;
                        break;
                    }
                }
                if (flag4 == 0)
                {
                    cout << "Please enter the correct input" << endl;
                    channel_selection();
                    return false;
                }
            }

            else if (channel[i].channel_num > 16 && channel[i].channel_num < 21)
            {
                int flag5 = 0;
                for (int j = 0; j <= g; j++)
                {
                    if (genre[j] == 5)
                    {
                        flag5 = 1;
                        break;
                    }
                }
                if (flag5 == 0)
                {
                    cout << "Please enter the correct input" << endl;
                    channel_selection();
                    return false;
                }
            }

            else if (channel[i].channel_num > 20 && channel[i].channel_num < 24)
            {
                int flag7 = 0;
                for (int j = 0; j <= g; j++)
                {
                    if (genre[j] == 7)
                    {
                        flag7 = 1;
                        break;
                    }
                }
                if (flag7 == 0)
                {
                    cout << "Please enter the correct input" << endl;
                    channel_selection();
                    return false;
                }
            }

            else
            {
                cout << "Please enter the correct input" << endl;
                channel_selection();
                return false;
            }
        }

        if (channel[i].channel_code == 'P')
        {
            if (channel[i].channel_num > 0 && channel[i].channel_num < 3)
            {
                int flag1 = 0;
                for (int j = 0; j <= g; j++)
                {
                    if (genre[j] == 1)
                    {
                        flag1 = 1;
                        break;
                    }
                }
                if (flag1 == 0)
                {
                    cout << "Please enter the correct input" << endl;
                    channel_selection();
                    return false;
                }
            }

            else if (channel[i].channel_num > 2 && channel[i].channel_num < 6)
            {
                int flag2 = 0;
                for (int j = 0; j <= g; j++)
                {
                    if (genre[j] == 2)
                    {
                        flag2 = 1;
                        break;
                    }
                }
                if (flag2 == 0)
                {
                    cout << "Please enter the correct input" << endl;
                    channel_selection();
                    return false;
                }
            }

            else if (channel[i].channel_num > 5 && channel[i].channel_num < 10)
            {
                int flag3 = 0;
                for (int j = 0; j <= g; j++)
                {
                    if (genre[j] == 3)
                    {
                        flag3 = 1;
                        break;
                    }
                }
                if (flag3 == 0)
                {
                    cout << "Please enter the correct input" << endl;
                    channel_selection();
                    return false;
                }
            }

            else if (channel[i].channel_num > 9 && channel[i].channel_num < 15)
            {
                int flag5 = 0;
                for (int j = 0; j <= g; j++)
                {
                    if (genre[j] == 5)
                    {
                        flag5 = 1;
                        break;
                    }
                }
                if (flag5 == 0)
                {
                    cout << "Please enter the correct input" << endl;
                    channel_selection();
                    return false;
                }
            }

            else
            {
                cout << "Please enter the correct input" << endl;
                channel_selection();
                return false;
            }
        }
    }
    return true;
}

void Channel ::select_all_channels_calculate_price()
{
    total_price = 0;

    for (int i = 0; i <= l; i++)
    {
        for (int j = 0; j <= g; j++)
        {
            if (language[i] == 1)
            {
                if (genre[j] == 1)
                    total_price += 29.3;
                if (genre[j] == 2)
                    total_price += 96.9;
                if (genre[j] == 3)
                    total_price += 14.8;
                if (genre[j] == 4)
                    total_price += 97.9;
                if (genre[j] == 5)
                    total_price += 10.3;
                if (genre[j] == 6)
                    total_price += 19.1;
                if (genre[j] == 7)
                    total_price += 34.1;
            }
            if (language[i] == 2)
            {
                if (genre[j] == 1)
                    total_price += 129.82;
                if (genre[j] == 2)
                    total_price += 72.8;
                if (genre[j] == 3)
                    total_price += 2.9;
                if (genre[j] == 4)
                    total_price += 45.3;
                if (genre[j] == 5)
                    total_price += 14.2;
                if (genre[j] == 6)
                    total_price += 9.3;
                if (genre[j] == 7)
                    total_price += 24.2;
            }
            if (language[i] == 3)
            {
                if (genre[j] == 1)
                    total_price += 101.3;
                if (genre[j] == 2)
                    total_price += 77.6;
                if (genre[j] == 3)
                    total_price += 22.0;
                if (genre[j] == 4)
                    total_price += 44.8;
                if (genre[j] == 5)
                    total_price += 14.8;
                if (genre[j] == 7)
                    total_price += 24.2;
            }
            if (language[i] == 4)
            {
                if (genre[j] == 1)
                    total_price += 64.4;
                if (genre[j] == 2)
                    total_price += 37.7;
                if (genre[j] == 3)
                    total_price += 9.8;
                if (genre[j] == 4)
                    total_price += 44.8;
                if (genre[j] == 5)
                    total_price += 11.3;
                if (genre[j] == 7)
                    total_price += 24.2;
            }
            if (language[i] == 5)
            {
                if (genre[j] == 1)
                    total_price += 8.8;
                if (genre[j] == 2)
                    total_price += 14.2;
                if (genre[j] == 3)
                    total_price += 10.4;
                if (genre[j] == 5)
                    total_price += 11.7;
            }
        }
    }
    cout << endl
         << "You selected all channels" << endl
         << "Total price: " << total_price << endl;
    change_channel();
    system("cls");
    // select_free_channels();
}

void Channel ::change_channel()
{
    cout << "Do you want to change your options?" << endl
         << "1. Yes" << endl
         << "2. No" << endl;
    int change;
    cin >> change;
    if (change == 1)
    {
        system("cls");
        display_channel();
        channel_selection_options();
    }
    else if (change == 2)
    {
        return;
    }
    else
    {
        cout << "Please enter correct input" << endl;
        change_channel();
    }
}

void Channel ::calculate_channel_price()
{
    total_price = 0;
    for (int i = 0; i <= c; i++)
    {
        if (channel[i].channel_code == 'E')
        {
            if (channel[i].channel_num == 1)
                total_price += 5.9;
            if (channel[i].channel_num == 2)
                total_price += 5.9;
            if (channel[i].channel_num == 3)
                total_price += 5.7;
            if (channel[i].channel_num == 4)
                total_price += 11.8;
            if (channel[i].channel_num == 5)
                total_price += 17.7;
            if (channel[i].channel_num == 6)
                total_price += 15.5;
            if (channel[i].channel_num == 7)
                total_price += 5.9;
            if (channel[i].channel_num == 8)
                total_price += 5.9;
            if (channel[i].channel_num == 9)
                total_price += 11.8;
            if (channel[i].channel_num == 10)
                total_price += 5.9;
            if (channel[i].channel_num == 11)
                total_price += 11.8;
            if (channel[i].channel_num == 12)
                total_price += 22.4;
            if (channel[i].channel_num == 13)
                total_price += 1.7;
            if (channel[i].channel_num == 14)
                total_price += 0.5;
            if (channel[i].channel_num == 15)
                total_price += 2.3;
            if (channel[i].channel_num == 16)
                total_price += 2.9;
            if (channel[i].channel_num == 17)
                total_price += 0.6;
            if (channel[i].channel_num == 18)
                total_price += 1.1;
            if (channel[i].channel_num == 19)
                total_price += 1.1;
            if (channel[i].channel_num == 20)
                total_price += 1.1;
            if (channel[i].channel_num == 21)
                total_price += 3.5;
            if (channel[i].channel_num == 22)
                total_price += 4.7;
            if (channel[i].channel_num == 23)
                total_price += 4.1;
            if (channel[i].channel_num == 24)
                total_price += 22.4;
            if (channel[i].channel_num == 25)
                total_price += 4.7;
            if (channel[i].channel_num == 26)
                total_price += 8.2;
            if (channel[i].channel_num == 27)
                total_price += 22.2;
            if (channel[i].channel_num == 28)
                total_price += 22.2;
            if (channel[i].channel_num == 29)
                total_price += 9.4;
            if (channel[i].channel_num == 30)
                total_price += 3.5;
            if (channel[i].channel_num == 31)
                total_price += 2.5;
            if (channel[i].channel_num == 32)
                total_price += 0.7;
            if (channel[i].channel_num == 33)
                total_price += 2.5;
            if (channel[i].channel_num == 34)
                total_price += 1.1;
            if (channel[i].channel_num == 35)
                total_price += 2.3;
            if (channel[i].channel_num == 36)
                total_price += 4.7;
            if (channel[i].channel_num == 37)
                total_price += 1.7;
            if (channel[i].channel_num == 38)
                total_price += 1.1;
            if (channel[i].channel_num == 39)
                total_price += 3.5;
            if (channel[i].channel_num == 40)
                total_price += 3.5;
            if (channel[i].channel_num == 41)
                total_price += 2.3;
            if (channel[i].channel_num == 42)
                total_price += 5.2;
            if (channel[i].channel_num == 43)
                total_price += 11.8;
            if (channel[i].channel_num == 44)
                total_price += 4.7;
            if (channel[i].channel_num == 45)
                total_price += 7.2;
            if (channel[i].channel_num == 46)
                total_price += 5.2;
        }

        if (channel[i].channel_code == 'H')
        {
            if (channel[i].channel_num == 1)
                total_price += 7.1;
            if (channel[i].channel_num == 2)
                total_price += 8.2;
            if (channel[i].channel_num == 3)
                total_price += 0.2;
            if (channel[i].channel_num == 4)
                total_price += 22.4;
            if (channel[i].channel_num == 5)
                total_price += 1.1;
            if (channel[i].channel_num == 6)
                total_price += 22.4;
            if (channel[i].channel_num == 7)
                total_price += 0.6;
            if (channel[i].channel_num == 8)
                total_price += 22.4;
            if (channel[i].channel_num == 9)
                total_price += 22.4;
            if (channel[i].channel_num == 10)
                total_price += 0.6;
            if (channel[i].channel_num == 11)
                total_price += 0.2;
            if (channel[i].channel_num == 12)
                total_price += 22.4;
            if (channel[i].channel_num == 13)
                total_price += 3.5;
            if (channel[i].channel_num == 14)
                total_price += 17.7;
            if (channel[i].channel_num == 15)
                total_price += 1.1;
            if (channel[i].channel_num == 16)
                total_price += 1.1;
            if (channel[i].channel_num == 17)
                total_price += 22.4;
            if (channel[i].channel_num == 18)
                total_price += 1.1;
            if (channel[i].channel_num == 19)
                total_price += 3.5;
            if (channel[i].channel_num == 20)
                total_price += 22.4;
            if (channel[i].channel_num == 21)
                total_price += 0.8;
            if (channel[i].channel_num == 22)
                total_price += 0.1;
            if (channel[i].channel_num == 23)
                total_price += 0.2;
            if (channel[i].channel_num == 24)
                total_price += 0.4;
            if (channel[i].channel_num == 25)
                total_price += 1.1;
            if (channel[i].channel_num == 26)
                total_price += 0.1;
            if (channel[i].channel_num == 27)
                total_price += 0.1;
            if (channel[i].channel_num == 28)
                total_price += 0.1;
            if (channel[i].channel_num == 29)
                total_price += 22.4;
            if (channel[i].channel_num == 30)
                total_price += 22.4;
            if (channel[i].channel_num == 31)
                total_price += 0.5;
            if (channel[i].channel_num == 32)
                total_price += 0.5;
            if (channel[i].channel_num == 33)
                total_price += 1.1;
            if (channel[i].channel_num == 34)
                total_price += 3.5;
            if (channel[i].channel_num == 35)
                total_price += 4.5;
            if (channel[i].channel_num == 36)
                total_price += 0.1;
            if (channel[i].channel_num == 37)
                total_price += 4.5;
            if (channel[i].channel_num == 38)
                total_price += 2.3;
            if (channel[i].channel_num == 39)
                total_price += 4.7;
            if (channel[i].channel_num == 40)
                total_price += 2.3;
            if (channel[i].channel_num == 41)
                total_price += 11.8;
            if (channel[i].channel_num == 42)
                total_price += 7.2;
            if (channel[i].channel_num == 43)
                total_price += 5.2;
        }

        if (channel[i].channel_code == 'T')
        {
            if (channel[i].channel_num == 1)
                total_price += 3.5;
            if (channel[i].channel_num == 2)
                total_price += 22.4;
            if (channel[i].channel_num == 3)
                total_price += 2.3;
            if (channel[i].channel_num == 4)
                total_price += 5.9;
            if (channel[i].channel_num == 5)
                total_price += 22.4;
            if (channel[i].channel_num == 6)
                total_price += 22.4;
            if (channel[i].channel_num == 7)
                total_price += 22.4;
            if (channel[i].channel_num == 8)
                total_price += 15.3;
            if (channel[i].channel_num == 9)
                total_price += 20.1;
            if (channel[i].channel_num == 10)
                total_price += 8.2;
            if (channel[i].channel_num == 11)
                total_price += 22.2;
            if (channel[i].channel_num == 12)
                total_price += 11.8;
            if (channel[i].channel_num == 13)
                total_price += 2.4;
            if (channel[i].channel_num == 14)
                total_price += 2.6;
            if (channel[i].channel_num == 15)
                total_price += 1.8;
            if (channel[i].channel_num == 16)
                total_price += 4.6;
            if (channel[i].channel_num == 17)
                total_price += 3.2;
            if (channel[i].channel_num == 18)
                total_price += 2.4;
            if (channel[i].channel_num == 19)
                total_price += 3.2;
            if (channel[i].channel_num == 20)
                total_price += 1.8;
            if (channel[i].channel_num == 21)
                total_price += 22.4;
            if (channel[i].channel_num == 22)
                total_price += 22.4;
            if (channel[i].channel_num == 23)
                total_price += 4.7;
            if (channel[i].channel_num == 24)
                total_price += 5.4;
            if (channel[i].channel_num == 25)
                total_price += 4.7;
            if (channel[i].channel_num == 26)
                total_price += 11.8;
            if (channel[i].channel_num == 27)
                total_price += 7.2;
            if (channel[i].channel_num == 28)
                total_price += 5.2;
        }

        if (channel[i].channel_code == 'K')
        {
            if (channel[i].channel_num == 1)
                total_price += 3.5;
            if (channel[i].channel_num == 2)
                total_price += 3.5;
            if (channel[i].channel_num == 3)
                total_price += 5.4;
            if (channel[i].channel_num == 4)
                total_price += 7.2;
            if (channel[i].channel_num == 5)
                total_price += 22.4;
            if (channel[i].channel_num == 6)
                total_price += 22.4;
            if (channel[i].channel_num == 7)
                total_price += 3.5;
            if (channel[i].channel_num == 8)
                total_price += 22.4;
            if (channel[i].channel_num == 9)
                total_price += 11.8;
            if (channel[i].channel_num == 10)
                total_price += 0.2;
            if (channel[i].channel_num == 11)
                total_price += 4.6;
            if (channel[i].channel_num == 12)
                total_price += 0.2;
            if (channel[i].channel_num == 13)
                total_price += 0.2;
            if (channel[i].channel_num == 14)
                total_price += 4.6;
            if (channel[i].channel_num == 15)
                total_price += 22.4;
            if (channel[i].channel_num == 16)
                total_price += 22.4;
            if (channel[i].channel_num == 17)
                total_price += 1.5;
            if (channel[i].channel_num == 18)
                total_price += 2.4;
            if (channel[i].channel_num == 19)
                total_price += 1.5;
            if (channel[i].channel_num == 20)
                total_price += 5.9;
            if (channel[i].channel_num == 21)
                total_price += 11.8;
            if (channel[i].channel_num == 22)
                total_price += 5.2;
            if (channel[i].channel_num == 23)
                total_price += 7.2;
        }

        if (channel[i].channel_code == 'P')
        {
            if (channel[i].channel_num == 1)
                total_price += 4.5;
            if (channel[i].channel_num == 2)
                total_price += 4.3;
            if (channel[i].channel_num == 3)
                total_price += 1.2;
            if (channel[i].channel_num == 4)
                total_price += 1.2;
            if (channel[i].channel_num == 5)
                total_price += 11.8;
            if (channel[i].channel_num == 6)
                total_price += 4.5;
            if (channel[i].channel_num == 7)
                total_price += 3.5;
            if (channel[i].channel_num == 8)
                total_price += 1.2;
            if (channel[i].channel_num == 9)
                total_price += 1.2;
            if (channel[i].channel_num == 10)
                total_price += 4.5;
            if (channel[i].channel_num == 11)
                total_price += 2.1;
            if (channel[i].channel_num == 12)
                total_price += 2.1;
            if (channel[i].channel_num == 13)
                total_price += 1.8;
            if (channel[i].channel_num == 14)
                total_price += 1.2;
        }
    }

    cout << "Total price: " << total_price << endl;
}

void Channel ::select_free_channels()
{
    system("cls");
    fstream FileName;
    FileName.open("Free_channels.txt", ios::in);
    string st;
    while (FileName.eof() == 0)
    {
        getline(FileName, st);
        cout << st << endl;
    }
    FileName.close();

    cout << "Free Channels are added to your pack" << endl;
    cout << "Press 1 to continue" << endl;
    cin >> free_channel_option;
    while (free_channel_option != 1)
    {
        cout << "Please press 1 to continue" << endl;
        cin >> free_channel_option;
    }
    system("cls");

    fstream fileptr;
    fileptr.open("All_users_history.txt", ios::app);

    for (int i = 0; i <= c; i++)
    {
        fileptr << channel[i].channel_code << channel[i].channel_num << " ";
    }
    fileptr << endl;
    fileptr.close();
    // system("cls");
}

void Channel ::display_total_cost()
{

    double box_cost = 499;
    fstream fileptr;
    double price_month_3, price_month_6, price_year;
    if (channel_option == 1)
    {

        cout << "You selected all channels" << endl;
        cout << "45 Free channels are added to your pack" << endl;
        cout << "Select from these pack options" << endl;
        cout << endl
             << endl;
        cout << "   Box cost: " << box_cost << endl;
    }
    if (channel_option == 2)
    {
        cout << "Selected channels:" << endl;
        for (int i = 0; i <= c; i++)
        {
            cout << channel[i].channel_code << channel[i].channel_num << " ";
        }
        cout << endl;
        cout << "45 Free channels are added to your pack" << endl;
        cout << "Select from these pack options" << endl;
        cout << endl
             << endl;
        cout << "   Box cost: " << box_cost << endl;
    }

    price_month_3 = (total_price * 3) - 0.05 * (total_price * 3);
    price_month_6 = (total_price * 6) - 0.1 * (total_price * 6);
    price_year = (total_price * 12) - 0.15 * (total_price * 12);

    cout << "1. Rs. " << total_price << " / month" << endl;

    cout << "2. Rs. " << price_month_3 << " / 3 months" << endl;

    cout << "3. Rs. " << price_month_6 << " / 6 months" << endl;

    cout << "4. Rs. " << price_year << " / 12 months" << endl;

    int choice;
    cin >> choice;
    while (choice != 1 && choice != 2 && choice != 3 && choice != 4)
    {
        cout << "Please enter a valid input: ";
        cin >> choice;
    }

    if (channel_option == 3)
    {

        if (choice == 1)
        {
            cout << "Total price: " << total_price << endl;
            channel_months = 1;
            fileptr.open("temp_all_users_history.txt", ios::app);
            fileptr << total_price << endl;
            fileptr << 1 << endl;
            fileptr.close();
        }
        else if (choice == 2)
        {
            cout << "Total price: " << price_month_3 << endl;
            channel_months = 3;
            fileptr.open("temp_all_users_history.txt", ios::app);
            fileptr << price_month_3 << endl;
            fileptr << 3 << endl;
            fileptr.close();
        }
        else if (choice == 3)
        {
            cout << "Total price: " << price_month_6 << endl;
            channel_months = 6;
            fileptr.open("temp_all_users_history.txt", ios::app);
            fileptr << price_month_6 << endl;
            fileptr << 6 << endl;
            fileptr.close();
        }
        else if (choice == 4)
        {
            cout << "Total price: " << price_year << endl;
            channel_months = 12;
            fileptr.open("temp_all_users_history.txt", ios::app);
            fileptr << price_year << endl;
            fileptr << 12 << endl;
            fileptr.close();
        }
    }

    else
    {
        if (choice == 1)
        {
            fileptr.open("All_users_history.txt", ios::app);
            fileptr << total_price << endl;
            fileptr << 1 << endl;
            cout << "Total price: " << total_price + box_cost << endl;
            fileptr.close();
        }
        else if (choice == 2)
        {
            fileptr.open("All_users_history.txt", ios::app);
            fileptr << price_month_3 << endl;
            fileptr << 3 << endl;
            cout << "Total price: " << price_month_3 + box_cost << endl;
            fileptr.close();
        }
        else if (choice == 3)
        {
            fileptr.open("All_users_history.txt", ios::app);
            fileptr << price_month_6 << endl;
            fileptr << 6 << endl;
            cout << "Total price: " << price_month_6 + box_cost << endl;
            fileptr.close();
        }
        else if (choice == 4)
        {
            fileptr.open("All_users_history.txt", ios::app);
            fileptr << price_year << endl;
            fileptr << 12 << endl;
            cout << "Total price: " << price_year + box_cost << endl;
            fileptr.close();
        }

        fileptr.open("All_users_history.txt", ios::app);
        auto currentTime = chrono::system_clock::now();
        time_t oldTime_t = chrono::system_clock::to_time_t(currentTime);
        fileptr << ctime(&oldTime_t);
        if (choice == 1)
        {
            auto newTime = currentTime + chrono::hours(24 * 30);
            time_t newTime_t = chrono::system_clock::to_time_t(newTime);
            fileptr << ctime(&newTime_t);
        }
        else if (choice == 2)
        {
            auto newTime = currentTime + chrono::hours(24 * 90);
            time_t newTime_t = chrono::system_clock::to_time_t(newTime);
            fileptr << ctime(&newTime_t);
        }
        else if (choice == 3)
        {
            auto newTime = currentTime + chrono::hours(24 * 180);
            time_t newTime_t = chrono::system_clock::to_time_t(newTime);
            fileptr << ctime(&newTime_t);
        }
        else if (choice == 4)
        {
            auto newTime = currentTime + chrono::hours(24 * 360);
            time_t newTime_t = chrono::system_clock::to_time_t(newTime);
            fileptr << ctime(&newTime_t);
        }

        fileptr.close();
    }
    cout << endl
         << endl;
    cout << "Press 1 to continue" << endl;
    char ch;
    cin >> ch;
    // system("cls");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 10);

    fstream file;
    string str;
    cout << endl
         << endl;
    file.open("thank_you.txt", ios::in);
    while (file.eof() == 0)
    {
        getline(file, str);

        cout << "                " << str << endl;
        Sleep(500);
    }
    file.close();
    cout << endl
         << endl;
    SetConsoleTextAttribute(hConsole, 7);
}

void Channel::store_channels_in_structure_array()
{
    int count = 0;
    for (int i = 0; i <= l; i++)
    {
        if (language[i] == 1)
        {
            for (int j = 0; j <= g; j++)
            {
                if (genre[j] == 1)
                {
                    for (int k = 1; k < 5; k++)
                    {
                        channel[count].channel_code = 'E';
                        channel[count].channel_num = k;
                        count++;
                    }
                }
                else if (genre[j] == 2)
                {
                    for (int k = 5; k < 13; k++)
                    {
                        channel[count].channel_code = 'E';
                        channel[count].channel_num = k;
                        count++;
                    }
                }
                else if (genre[j] == 3)
                {
                    for (int k = 13; k < 22; k++)
                    {
                        channel[count].channel_code = 'E';
                        channel[count].channel_num = k;
                        count++;
                    }
                }
                else if (genre[j] == 4)
                {
                    for (int k = 22; k < 30; k++)
                    {
                        channel[count].channel_code = 'E';
                        channel[count].channel_num = k;
                        count++;
                    }
                }
                else if (genre[j] == 5)
                {
                    for (int k = 30; k < 35; k++)
                    {
                        channel[count].channel_code = 'E';
                        channel[count].channel_num = k;
                        count++;
                    }
                }
                else if (genre[j] == 6)
                {
                    for (int k = 35; k < 42; k++)
                    {
                        channel[count].channel_code = 'E';
                        channel[count].channel_num = k;
                        count++;
                    }
                }
                else
                {
                    for (int k = 42; k < 47; k++)
                    {
                        channel[count].channel_code = 'E';
                        channel[count].channel_num = k;
                        count++;
                    }
                }
            }
        }
        else if (language[i] == 2)
        {
            for (int j = 0; j <= g; j++)
            {
                if (genre[j] == 1)
                {
                    for (int k = 1; k < 13; k++)
                    {
                        channel[count].channel_code = 'H';
                        channel[count].channel_num = k;
                        count++;
                    }
                }
                else if (genre[j] == 2)
                {
                    for (int k = 13; k < 21; k++)
                    {
                        channel[count].channel_code = 'H';
                        channel[count].channel_num = k;
                        count++;
                    }
                }
                else if (genre[j] == 3)
                {
                    for (int k = 21; k < 29; k++)
                    {
                        channel[count].channel_code = 'H';
                        channel[count].channel_num = k;
                        count++;
                    }
                }
                else if (genre[j] == 4)
                {
                    for (int k = 29; k < 32; k++)
                    {
                        channel[count].channel_code = 'H';
                        channel[count].channel_num = k;
                        count++;
                    }
                }
                else if (genre[j] == 5)
                {
                    for (int k = 32; k < 38; k++)
                    {
                        channel[count].channel_code = 'H';
                        channel[count].channel_num = k;
                        count++;
                    }
                }
                else if (genre[j] == 6)
                {
                    for (int k = 38; k < 41; k++)
                    {
                        channel[count].channel_code = 'H';
                        channel[count].channel_num = k;
                        count++;
                    }
                }
                else
                {
                    for (int k = 41; k < 44; k++)
                    {
                        channel[count].channel_code = 'H';
                        channel[count].channel_num = k;
                        count++;
                    }
                }
            }
        }
        else if (language[i] == 3)
        {
            for (int j = 0; j <= g; j++)
            {
                if (genre[j] == 1)
                {
                    for (int k = 1; k < 8; k++)
                    {
                        channel[count].channel_code = 'T';
                        channel[count].channel_num = k;
                        count++;
                    }
                }
                else if (genre[j] == 2)
                {
                    for (int k = 8; k < 13; k++)
                    {
                        channel[count].channel_code = 'T';
                        channel[count].channel_num = k;
                        count++;
                    }
                }
                else if (genre[j] == 3)
                {
                    for (int k = 13; k < 21; k++)
                    {
                        channel[count].channel_code = 'T';
                        channel[count].channel_num = k;
                        count++;
                    }
                }
                else if (genre[j] == 4)
                {
                    for (int k = 21; k < 23; k++)
                    {
                        channel[count].channel_code = 'T';
                        channel[count].channel_num = k;
                        count++;
                    }
                }
                else if (genre[j] == 5)
                {
                    for (int k = 23; k < 26; k++)
                    {
                        channel[count].channel_code = 'T';
                        channel[count].channel_num = k;
                        count++;
                    }
                }
                else if (genre[j] == 7)
                {
                    for (int k = 26; k < 29; k++)
                    {
                        channel[count].channel_code = 'T';
                        channel[count].channel_num = k;
                        count++;
                    }
                }
            }
        }
        else if (language[i] == 4)
        {
            for (int j = 0; j <= g; j++)
            {
                if (genre[j] == 1)
                {
                    for (int k = 1; k < 7; k++)
                    {
                        channel[count].channel_code = 'K';
                        channel[count].channel_num = k;
                        count++;
                    }
                }
                else if (genre[j] == 2)
                {
                    for (int k = 7; k < 10; k++)
                    {
                        channel[count].channel_code = 'K';
                        channel[count].channel_num = k;
                        count++;
                    }
                }
                else if (genre[j] == 3)
                {
                    for (int k = 10; k < 15; k++)
                    {
                        channel[count].channel_code = 'K';
                        channel[count].channel_num = k;
                        count++;
                    }
                }
                else if (genre[j] == 4)
                {
                    for (int k = 15; k < 17; k++)
                    {
                        channel[count].channel_code = 'K';
                        channel[count].channel_num = k;
                        count++;
                    }
                }
                else if (genre[j] == 5)
                {
                    for (int k = 17; k < 21; k++)
                    {
                        channel[count].channel_code = 'K';
                        channel[count].channel_num = k;
                        count++;
                    }
                }
                else if (genre[j] == 7)
                {
                    for (int k = 21; k < 24; k++)
                    {
                        channel[count].channel_code = 'K';
                        channel[count].channel_num = k;
                        count++;
                    }
                }
            }
        }
        else
        {
            for (int j = 0; j <= g; j++)
            {
                if (genre[j] == 1)
                {
                    for (int k = 1; k < 3; k++)
                    {
                        channel[count].channel_code = 'P';
                        channel[count].channel_num = k;
                        count++;
                    }
                }
                else if (genre[j] == 2)
                {
                    for (int k = 3; k < 6; k++)
                    {
                        channel[count].channel_code = 'P';
                        channel[count].channel_num = k;
                        count++;
                    }
                }
                else if (genre[j] == 3)
                {
                    for (int k = 6; k < 10; k++)
                    {
                        channel[count].channel_code = 'P';
                        channel[count].channel_num = k;
                        count++;
                    }
                }
                else if (genre[j] == 5)
                {
                    for (int k = 10; k < 15; k++)
                    {
                        channel[count].channel_code = 'P';
                        channel[count].channel_num = k;
                        count++;
                    }
                }
            }
        }
    }
    c = count - 1;
}

// notacustomer class
class NotACustomer
{
public:
    string name;
    string mobile_no;
    string pincode;
    void setData();
    void store_user_history();

private:
    string username;
    string password;
    string favorite_place;
    string favorite_food;
    void store_details_in_file();

    void setName();
    void setMobile_no();
    void setPincode();
    void setUsername();
    void setPassword();
    void setFavoritePlace();
    void setFavoriteFood();
    bool check_name();
    bool check_mobile_no();
    bool check_pincode();
    bool check_username();
    bool check_password();
    bool check_favoriate_place();
    bool check_favoriate_food();
};

void NotACustomer::store_details_in_file()
{
    fstream fileptr;
    fileptr.open("store_security_details.txt", ios::app);
    fileptr << username << endl;
    fileptr << password << endl;
    fileptr << favorite_place << endl;
    fileptr << favorite_food << endl;
    fileptr.close();
}

void NotACustomer::setData()
{
    setName();
    setMobile_no();
    setPincode();
    setUsername();
    setPassword();
    setFavoritePlace();
    setFavoriteFood();
    system("cls");
    store_details_in_file();
}

void NotACustomer::store_user_history()
{
    fstream fileptr;
    fileptr.open("All_users_history.txt", ios::app);
    fileptr << username << endl;
    fileptr.close();
}

void NotACustomer::setName()
{
    cout << "Enter your name: ";
    fflush(stdin);
    getline(cin, name);
    bool verify_name = check_name();
    while (verify_name == false)
    {
        system("cls"); // system cls
        cout << "Invalid name" << endl;
        cout << "Enter a valid name: ";
        fflush(stdin);
        getline(cin, name);
        verify_name = check_name();
    }
}

void NotACustomer::setMobile_no()
{
    cout << "Enter your mobile number: ";
    fflush(stdin);
    getline(cin, mobile_no);
    bool verify_mobile_no = check_mobile_no();
    while (verify_mobile_no == false)
    {
        system("cls"); // system cls
        cout << "Enter a valid mobile number: ";
        fflush(stdin);
        getline(cin, mobile_no);
        verify_mobile_no = check_mobile_no();
    }
}

void NotACustomer::setPincode()
{
    cout << "Enter your pincode: ";
    fflush(stdin);
    getline(cin, pincode);
    bool verify_pincode = check_pincode();
    while (verify_pincode == false)
    {
        system("cls"); // system cls
        cout << "Enter a valid(6 digit) pincode: ";
        fflush(stdin);
        getline(cin, pincode);
        verify_pincode = check_pincode();
    }
}

void NotACustomer::setUsername()
{
    cout << "Set your username: ";
    fflush(stdin);
    getline(cin, username);
    bool verify_username = check_username();
    while (verify_username == false)
    {
        cout << "Enter your username: ";
        fflush(stdin);
        getline(cin, username);
        verify_username = check_username();
    }
}

void NotACustomer::setPassword()
{
    cout << "Set your password: ";
    fflush(stdin);
    getline(cin, password);
    bool verify_password = check_password();
    while (verify_password == false)
    {
        cout << "Enter your password: ";
        fflush(stdin);
        getline(cin, password);
        verify_password = check_password();
    }
}

void NotACustomer::setFavoritePlace()
{
    cout << "Enter your favorite place: ";
    fflush(stdin);
    getline(cin, favorite_place);
    bool verify_favorite_place = check_favoriate_place();
    while (verify_favorite_place == false)
    {
        system("cls"); // system cls
        cout << "Enter a valid place: ";
        fflush(stdin);
        getline(cin, favorite_place);
        verify_favorite_place = check_favoriate_place();
    }
}

void NotACustomer::setFavoriteFood()
{
    cout << "Enter your favorite food: ";
    fflush(stdin);
    getline(cin, favorite_food);
    bool verify_favorite_food = check_favoriate_food();
    while (verify_favorite_food == false)
    {
        system("cls"); // system cls
        cout << "Enter a valid food: ";
        fflush(stdin);
        getline(cin, favorite_food);
        verify_favorite_food = check_favoriate_food();
    }
}

bool NotACustomer::check_name()
{
    for (int i = 0; i < name.length(); i++)
    {
        if ((name[i] > 64 && name[i] < 91) || (name[i] > 96 && name[i] < 123) || name[i] == 32)
            ;
        else
        {
            return false;
        }
    }
    return true;
}

bool NotACustomer::check_mobile_no()
{
    if (mobile_no.length() != 10)
    {
        return false;
    }
    for (int i = 0; i < mobile_no.length(); i++)
    {
        if (mobile_no[i] > 47 && mobile_no[i] < 58)
            ;
        else
        {
            return false;
        }
    }
    return true;
}

bool NotACustomer::check_pincode()
{
    if (pincode.length() != 6)
    {
        return false;
    }
    for (int i = 0; i < pincode.length(); i++)
    {
        if (pincode[i] > 47 && pincode[i] < 58)
            ;
        else
        {
            return false;
        }
    }
    return true;
}

bool NotACustomer::check_username()
{
    if (username.length() < 5)
    {
        system("cls"); // system cls
        cout << " username must be at least 5 characters long" << endl;
        return false;
    }
    else if (username.length() > 20)
    {
        system("cls"); // system cls
        cout << "username atmost have 20 characters long" << endl;
        return false;
    }
    for (int i = 0; i < username.length(); i++)
    {
        if ((username[i] > 64 && username[i] < 91) || (username[i] > 96 && username[i] < 123) || (username[i] > 47 && username[i] < 58))
            ;
        else if (username[i] == 32)
        {
            system("cls"); // system cls
            cout << "username can not have spaces" << endl;
            return false;
        }
        else
        {
            system("cls"); // system cls
            cout << "special characters are not allowed" << endl;
            return false;
        }
    }
    // should write a code
    // Your username must be unique and not already in use by another stream box user.
    fstream fileptr;
    fileptr.open("store_security_details.txt", ios::in);
    string str;
    fileptr >> str;
    if (str.length() == 0)
    {
        fileptr.close();
        return true;
    }
    fileptr.close();

    fileptr.open("store_security_details.txt", ios::in);
    NotACustomer temp;
    do
    {
        getline(fileptr, temp.username);
        if (temp.username.length() == 0)
        {
            fileptr.close();
            return true;
        }
        if (username.compare(temp.username) == 0)
        {
            system("cls"); // system cls
            cout << "username already exists,try another" << endl;
            fileptr.close();
            return false;
        }
        getline(fileptr, temp.password);
        getline(fileptr, temp.favorite_place);
        getline(fileptr, temp.favorite_food);
    } while (fileptr.eof() == 0);

    fileptr.close();
    return true;
}

bool NotACustomer::check_password()
{
    if (password.length() < 8)
    {
        system("cls"); // system cls
        cout << "password should have a minimum length of 8 characters" << endl;
        return false;
    }
    int lower_case_count = 0;
    int upper_case_count = 0;
    int numerical_count = 0;
    int special_char_count = 0;
    for (int i = 0; i < password.length(); i++)
    {
        if (password[i] == 32)
        {
            system("cls"); // system cls
            cout << "password cannot have spaces" << endl;
            return false;
        }
        else if (password[i] > 64 && password[i] < 91)
        {
            upper_case_count++;
        }
        else if (password[i] > 96 && password[i] < 123)
        {
            lower_case_count++;
        }
        else if (password[i] > 47 && password[i] < 58)
        {
            numerical_count++;
        }
        else
        {
            special_char_count++;
        }
    }
    if (upper_case_count == 0)
    {
        system("cls"); // system cls
        cout << "password should have atleat one uppercase character" << endl;
        return false;
    }
    else if (lower_case_count == 0)
    {
        system("cls"); // system cls
        cout << "password should have atleast one lowercase character" << endl;
        return false;
    }
    else if (numerical_count == 0)
    {
        system("cls"); // system cls
        cout << "password should have atleast one numerical character" << endl;
        return false;
    }
    else if (special_char_count == 0)
    {
        system("cls"); // system cls
        cout << "password should have atleast one special character" << endl;
        return false;
    }
    return true;
}

bool NotACustomer::check_favoriate_place()
{
    for (int i = 0; i < favorite_place.length(); i++)
    {
        if ((favorite_place[i] > 64 && favorite_place[i] < 91) || (favorite_place[i] > 96 && favorite_place[i] < 123) || favorite_place[i] == 32)
            ;
        else
        {
            return false;
        }
    }
    return true;
}

bool NotACustomer::check_favoriate_food()
{
    for (int i = 0; i < favorite_food.length(); i++)
    {
        if ((favorite_food[i] > 64 && favorite_food[i] < 91) || (favorite_food[i] > 96 && favorite_food[i] < 123) || favorite_food[i] == 32 || (favorite_food[i] > 47 && favorite_food[i] < 58))
            ;
        else
        {
            return false;
        }
    }
    return true;
}

// existingCustomer class
class ExistingCustomer
{
private:
    string password;
    string favoriate_place;
    string favoriate_food;

public:
    string username;
    string booking_date, ending_date;
    int months;
    double price;
    string all_channels;
    bool setData();
    bool forgotPassword();
    void display_past_details();
    void display_options_for_existing_user();

private:
    bool setUsername();
    bool setPassword();
    bool check_correct_password();
    bool check_username();
    bool check_new_password();
};

bool ExistingCustomer::setData()
{
    if (setUsername())
    {
        if (setPassword())
        {
            return true;
        }
        system("cls"); // system cls
        return false;
    }
    system("cls"); // system cls
    return false;
}

bool ExistingCustomer::forgotPassword()
{
    cout << "Enter your username: ";
    fflush(stdin);
    getline(cin, username);
    bool verify_username = check_username();
    if (verify_username)
    {
        string fav_place, fav_food;
        cout << "Enter your favoriate place: ";
        fflush(stdin);
        getline(cin, fav_place);
        cout << "Enter your favoriate food: ";
        fflush(stdin);
        getline(cin, fav_food);
        if (favoriate_place.compare(fav_place) == 0 && favoriate_food.compare(fav_food) == 0)
        {
            cout << "Enter your new password: ";
            getline(cin, password);
            bool verify_passsord = check_new_password();
            while (verify_passsord == false)
            {
                cout << "Enter your new password: ";
                fflush(stdin);
                getline(cin, password);
                verify_passsord = check_new_password();
            }
            fstream fileptr1, fileptr2;
            fileptr1.open("store_security_details.txt", ios::in);
            fileptr2.open("temp_store_security_details.txt", ios::out);
            ExistingCustomer temp;
            do
            {
                getline(fileptr1, temp.username);
                if (temp.username.length() == 0)
                {
                    break;
                }
                if (username.compare(temp.username) == 0)
                {
                    getline(fileptr1, temp.password);
                    getline(fileptr1, temp.favoriate_place);
                    getline(fileptr1, temp.favoriate_food);
                    fileptr2 << temp.username << endl;
                    fileptr2 << password << endl;
                    fileptr2 << temp.favoriate_place << endl;
                    fileptr2 << temp.favoriate_food << endl;
                    continue;
                }
                getline(fileptr1, temp.password);
                getline(fileptr1, temp.favoriate_place);
                getline(fileptr1, temp.favoriate_food);
                fileptr2 << temp.username << endl;
                fileptr2 << temp.password << endl;
                fileptr2 << temp.favoriate_place << endl;
                fileptr2 << temp.favoriate_food << endl;
            } while (fileptr1.eof() == 0);
            fileptr1.close();
            fileptr2.close();

            fileptr1.open("store_security_details.txt", ios::out);
            fileptr2.open("temp_store_security_details.txt", ios::in);
            string str;
            do
            {
                getline(fileptr2, str);
                if (str.length() == 0)
                {
                    break;
                }
                fileptr1 << str << endl;
            } while (fileptr2.eof() == 0);
            fileptr1.close();
            fileptr2.close();
            return true;
        }
        else
        {
            cout << "Invalid details" << endl;
            return false;
        }
    }

    return false;
}

void ExistingCustomer::display_past_details()
{
    fstream fileptr;
    string name_user;
    string buffer;
    fileptr.open("All_users_history.txt", ios::in);
    while (fileptr.eof() == 0)
    {
        getline(fileptr, name_user);
        getline(fileptr, all_channels);
        fileptr >> price;
        fileptr >> months;
        getline(fileptr, buffer);
        getline(fileptr, booking_date);
        getline(fileptr, ending_date);
        if (username.compare(name_user) == 0)
        {
            cout << "Username: " << name_user << endl;
            cout << "Selected Channels: " << endl
                 << all_channels << endl;
            cout << "You paid Rs. " << price << " for " << months << " months." << endl;
            cout << "Booking date: " << endl
                 << booking_date << endl;
            cout << "Valid upto: " << endl
                 << ending_date << endl;
            break;
        }
    }
    fileptr.close();
}

void ExistingCustomer::display_options_for_existing_user()
{
    int choice;
    cout << endl;
    cout << endl;
    cout << "1.Do you want to continue with the same pack after " << months << " months?" << endl;
    cout << "2.Back" << endl;

    cin >> choice;
    while (choice != 2 && choice != 1)
    {
        cout << "Please enter a vaid choice: ";
        cin >> choice;
    }
    system("cls");
    if (choice == 1)
    {
        string name_user, buffer;
        string new_total_channels;
        double new_price;
        int new_months;
        string new_booked_date, new_valid_date;
        fstream fileptr1, fileptr2;

        fileptr1.open("All_users_history.txt", ios::in);
        fileptr2.open("temp_all_users_history.txt", ios::out);

        while (fileptr1.eof() == 0)
        {
            getline(fileptr1, name_user);
            if (name_user.length() == 0)
            {
                break;
            }
            getline(fileptr1, new_total_channels);
            fileptr1 >> new_price;
            fileptr1 >> new_months;
            getline(fileptr1, buffer);
            getline(fileptr1, new_booked_date);
            getline(fileptr1, new_valid_date);

            if (username.compare(name_user) == 0)
            {
                fileptr2 << name_user << endl;
                fileptr2 << new_total_channels << endl;
                fileptr2.close();
                Channel obj;
                obj.channel_option = 3;
                obj.total_price = price;
                obj.total_price /= months;
                obj.display_total_cost();

                fileptr2.open("temp_all_users_history.txt", ios::app);
                auto currentTime = chrono::system_clock::now();
                time_t oldTime_t = chrono::system_clock::to_time_t(currentTime);
                fileptr2 << ctime(&oldTime_t);

                tm timeInfo = {};
                istringstream dateStream(new_valid_date);
                dateStream >> get_time(&timeInfo, "%a %b %d %H:%M:%S %Y");
                time_t time = mktime(&timeInfo);

                time += obj.channel_months * 30 * 24 * 60 * 60; // 3 days * 24 hours * 60 minutes * 60 seconds
                tm *newTimeInfo = localtime(&time);
                fileptr2 << put_time(newTimeInfo, "%a %b %d %H:%M:%S %Y") << endl;

                continue;
            }
            fileptr2 << name_user << endl;
            fileptr2 << new_total_channels << endl;
            fileptr2 << new_price << endl;
            fileptr2 << new_months << endl;
            fileptr2 << new_booked_date << endl;
            fileptr2 << new_valid_date << endl;
        }
        fileptr1.close();

        string temp_string;
        fstream file1, file2;
        file1.open("temp_all_users_history.txt", ios::in);
        file2.open("All_users_history.txt", ios::out);
        while (file1.eof() == 0)
        {
            getline(file1, temp_string);
            file2 << temp_string << endl;
        }
        file1.close();
        file2.close();
    }
    else
    {
        existing_customer_or_not();
    }
}

bool ExistingCustomer::setUsername()
{
    cout << "Enter your username: ";
    fflush(stdin);
    getline(cin, username);
    return check_username();
}

bool ExistingCustomer::setPassword()
{
    cout << "Enter your password: ";
    fflush(stdin);
    getline(cin, password);
    return check_correct_password();
}

bool ExistingCustomer::check_correct_password()
{
    fstream fileptr;
    fileptr.open("store_security_details.txt", ios::in);
    ExistingCustomer temp;
    do
    {
        getline(fileptr, temp.username);
        if (temp.username.length() == 0)
        {
            cout << "Invalid password" << endl;
            fileptr.close();
            return false;
        }
        getline(fileptr, temp.password);
        if (username.compare(temp.username) == 0 && password.compare(temp.password) == 0)
        {
            fileptr.close();
            return true;
        }
        getline(fileptr, temp.favoriate_place);
        getline(fileptr, temp.favoriate_food);
    } while (fileptr.eof() == 0);

    fileptr.close();
    cout << "Invalid password" << endl;
    return false;
}

bool ExistingCustomer::check_username()
{
    fstream fileptr;
    fileptr.open("store_security_details.txt", ios::in);
    string str;
    getline(fileptr, str);
    if (str.length() == 0)
    {
        cout << "username doesn't exist" << endl;
        fileptr.close();
        return false;
    }
    fileptr.close();
    fileptr.open("store_security_details.txt", ios::in);
    ExistingCustomer temp;
    do
    {
        getline(fileptr, temp.username);
        if (temp.username.length() == 0)
        {
            cout << "username doesn't exist" << endl;
            fileptr.close();
            return false;
        }
        if (username.compare(temp.username) == 0)
        {
            getline(fileptr, password);
            getline(fileptr, favoriate_place);
            getline(fileptr, favoriate_food);
            fileptr.close();
            return true;
        }
        getline(fileptr, temp.password);
        getline(fileptr, temp.favoriate_place);
        getline(fileptr, temp.favoriate_food);
    } while (fileptr.eof() == 0);
    fileptr.close();

    cout << "username doesn't exist" << endl;
    return false;
}

bool ExistingCustomer::check_new_password()
{
    if (password.length() < 8)
    {
        cout << "password should have a minimum length of 8 characters" << endl;
        return false;
    }
    int lower_case_count = 0;
    int upper_case_count = 0;
    int numerical_count = 0;
    int special_char_count = 0;
    for (int i = 0; i < password.length(); i++)
    {
        if (password[i] == 32)
        {
            cout << "password cannot have spaces" << endl;
            return false;
        }
        else if (password[i] > 64 && password[i] < 91)
        {
            upper_case_count++;
        }
        else if (password[i] > 96 && password[i] < 123)
        {
            lower_case_count++;
        }
        else if (password[i] > 47 && password[i] < 58)
        {
            numerical_count++;
        }
        else
        {
            special_char_count++;
        }
    }
    if (upper_case_count == 0)
    {
        cout << "password should have atleat one uppercase character" << endl;
        return false;
    }
    else if (lower_case_count == 0)
    {
        cout << "password should have atleast one lowercase character" << endl;
        return false;
    }
    else if (numerical_count == 0)
    {
        cout << "password should have atleast one numerical character" << endl;
        return false;
    }
    else if (special_char_count == 0)
    {
        cout << "password should have atleast one special character" << endl;
        return false;
    }
    return true;
}

int main()
{

    system("cls");
    display_platform();
    existing_customer_or_not();
}

void existing_customer_or_not()
{
    cout << "|----------------------|" << endl;
    cout << "|1. Existing Customer  |" << endl;
    cout << "|2. Not a Customer     |" << endl;
    cout << "|3. Exit               |" << endl;
    cout << "|----------------------|" << endl;
    int customer_or_not_choice;
    cin >> customer_or_not_choice;
    while (customer_or_not_choice != 1 && customer_or_not_choice != 2 && customer_or_not_choice != 3)
    {
        cout << "Enter a valid Choice: " << endl;
        cin >> customer_or_not_choice;
    }

    system("cls"); // system cls

    if (customer_or_not_choice == 2)
    {
        not_a_customer();
    }
    else if (customer_or_not_choice == 1)
    {
        existing_customer();
    }
    else
    {
        // exit
    }
}

void existing_customer()
{
    ExistingCustomer oldPerson;
try_again_and_forgot:
    if (oldPerson.setData())
    {
        // cout << "Welcome1" << endl;
        system("cls");
        oldPerson.display_past_details();
        oldPerson.display_options_for_existing_user();
        // procede after creating account
    }
    else
    {
        int try_forgot_choice;

        cout << "|--------------------|" << endl;
        cout << "|1. Try again        |" << endl;
        cout << "|2. Forgot password  |" << endl;
        cout << "|--------------------|" << endl;
        cin >> try_forgot_choice;
        while (try_forgot_choice != 1 && try_forgot_choice != 2)
        {
            cout << "Invalid Choice" << endl;
            cout << "Enter a valid Choice: " << endl;
            cin >> try_forgot_choice;
        }

        if (try_forgot_choice == 1)
        {
            system("cls"); // system cls
            goto try_again_and_forgot;
        }
        else
        {
            bool check_f_p = oldPerson.forgotPassword();
            if (check_f_p)
            {
                // cout << "welcome2" << endl;
                oldPerson.display_past_details();
                oldPerson.display_options_for_existing_user();
                // procede after entering password
            }
            else
            {
                existing_customer_or_not();
            }
        }
    }
}

void not_a_customer()
{
    NotACustomer newPerson;
    newPerson.setData();

    Channel obj3;
    obj3.display_language();
    obj3.language_selection();

    obj3.display_genre();
    obj3.genre_selection();

    obj3.display_channel();
    obj3.channel_selection_options();

    newPerson.store_user_history();
    obj3.select_free_channels();
    obj3.display_total_cost();
}

void display_platform()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 9);
    fstream fileptr;
    fileptr.open("platform.txt", ios::in);
    string str;

    int platform_count = 0;
    while (fileptr.eof() == 0)
    {
        if ((platform_count > 6 && platform_count < 16) || (platform_count > 18 && platform_count < 28))
        {
            getline(fileptr, str);
            cout << "        " << str[0];
            SetConsoleTextAttribute(hConsole, 10);
            for (int i = 1; i < str.length() - 1; i++)
            {
                cout << str[i];
            }
            SetConsoleTextAttribute(hConsole, 9);
            cout << str[str.length() - 1] << endl;
            platform_count++;
            Sleep(200);
            continue;
        }
        getline(fileptr, str);
        cout << "        " << str << endl;
        Sleep(200);
        platform_count++;
    }
    cout << endl
         << endl;
    SetConsoleTextAttribute(hConsole, 7);
}
