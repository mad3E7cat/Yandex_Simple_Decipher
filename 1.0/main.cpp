#include<iostream>
#include<stdlib.h>
#include<fstream> //не забыть чтение из файла
#include<conio.h>
#include<cstring>
using namespace std;
int main()
{
    metka_menu: //метка основного меню
    char menu=' ', navigate=' ';
    int menu_help=0, menu_algo=0;
    setlocale(LC_ALL,"Russian");
    system("cls");
    cout<<"###############################################################################"<<endl;
    cout<<"###############################################################################"<<endl;
    cout<<"#################                                              ################"<<endl;
    cout<<"################# Программа-криптоанализатор Simple Decipher++ ################"<<endl;
    cout<<"#################                                              ################"<<endl;
    cout<<"###############################################################################"<<endl;
    cout<<"###############################################################################"<<endl;
    cout<<"\t\n\n1. Расшифровать\n\n2. Посмотреть функционал\n\n3. О программе"<<endl;
    menu=getch(); //getch или cin
    if(menu=='1')
    {
        metka_error:
        char flag=' ';
        system("cls");
        // cout<<"\t\t\nМеню расшифровки: \n\n1. Алгоритм шифрования известен\n\n2. Алгоритм шифрования не известен"<<endl;
        //flag=getch();
        //if(flag=='1') //алгоритм известен
        if(1)
        {
            system("cls");
            cout<<"\n\t\t\tВыберите алгоритм:"<<endl;
            cout<<"\n1. Шифр Цезаря(сдвиг)"<<endl;
            cout<<"\n2. Азбука Морзе(английский алфавит)"<<endl;
            cout<<"\n3. Шифр Гронсфельда"<<endl;
            cout<<"\n4. Цифровые шифры(набор цифр)"<<endl;
            cout<<"\n5. Атбаш(замена)"<<endl;
            cout<<"\n6. Вертикальная перестановка(ПУНКТ МЕНЮ НЕ АКТИВЕН)"<<endl;
            cout<<"\n7. Шифр Бэкона"<<endl;
            cout<<"\n8. Шифр Вижинера(ПУНКТ МЕНЮ НЕ АКТИВЕН)"<<endl;
            cout<<"\n9. Частотный анализ(ПУНКТ МЕНЮ НЕ АКТИВЕН)"<<endl;
            cout<<"\n10. Клавиатурная шифровка"<<endl;
            cout<<"\n11. ASCII оцифровка"<<endl;
            cout<<"\n12. Солитер"<<endl;
            cout<<"\n\n\t\t-1 - назад\n\n\t\t0 - выход..."<<endl;
            cin>>menu_algo;
            if(menu_algo==-1) goto metka_menu;
            if((menu_algo<-1) or (menu_algo>12)) goto metka_error;
            if(menu_algo==1) //шифр цезаря
            {
                system("cls");
                cout<<"\n\tВведите текст: \n\n\t"<<endl;
                char english[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'}; //от 0 до 25=26 символов
                char decipher[256];
                char ciphertext[256];
                int ciphertext_digital[256];
                for(int i=0;i<=255;i++)
                {
                    ciphertext[i]='~';//инициализация,этот знак не встречается в текстовых шифрах
                    decipher[i]='~';
                }
                int i=0, simbol_count=0;
                char temporary='~';
                while(temporary!='\r'){
                    temporary=getche();
                    ciphertext[i]=temporary;
                    i++;
                    if(temporary!='\r') simbol_count++;
                }
                int key=-1,key_known=0;
                cout<<"\n\n1.Ключ известен\n\n2.Ключ не известен "<<endl;
                key_known=getch(); //getch!!!
                if(key_known=='1') //ключ известен
                {
                    system("cls");
                    cout<<"Введите ключ: "<<endl;
                    cin>>key;
                    system("cls");
                    cout<<"\nРасшифрованное сообщение:\n\n1. Сдвиг вправо:";
                    for(i=0;i<=simbol_count-1;i++)
                    {
                        for(int j=0;j<=25;j++)
                        {
                            if((ciphertext[i]==english[j])&&(ciphertext[i]!=' ')) ciphertext_digital[i]=j;
                        }
                        if(ciphertext[i]==' ')cout<<" ";
                        if(ciphertext[i]!=' ')cout<<english[(ciphertext_digital[i]+key)%26];
                    }
                    cout<<"\n2. Сдвиг влево:";
                    for(i=0;i<=simbol_count-1;i++)
                    {
                        for(int j=0;j<=25;j++)
                        {
                            if(ciphertext[i]==english[j]) ciphertext_digital[i]=j;
                        }
                        if(ciphertext[i]==' ')cout<<" ";
                        if(ciphertext[i]!=' ')cout<<english[(ciphertext_digital[i]-key+26)%26];
                    }
                    cout<<"\n"<<endl;
                    system("pause");
                }
                if(key_known=='2') //ключ не известен
                {
                    system("cls");
                    cout<<"Сдвиг вправо:\n\n";
                    for(key=1;key<=26;key++)
                    {
                        for(i=0;i<=simbol_count-1;i++)
                        {
                            for(int j=0;j<=25;j++)
                            {
                                if((ciphertext[i]==english[j])&&(ciphertext[i]!=' ')) ciphertext_digital[i]=j;
                            }
                            if(ciphertext[i]==' ')cout<<" ";
                            if(ciphertext[i]!=' ')cout<<english[(ciphertext_digital[i]+key)%26];
                        }
                        cout<<"\n"<<endl;
                    }
                    cout<<"\nСдвиг влево:\n";
                    for(key=1;key<=26;key++)
                    {
                        cout<<"\n"<<endl;
                        for(i=0;i<=simbol_count-1;i++)
                        {
                            for(int j=0;j<=25;j++)
                            {
                                if(ciphertext[i]==english[j]) ciphertext_digital[i]=j;
                            }
                            if(ciphertext[i]==' ')cout<<" ";
                            if(ciphertext[i]!=' ')cout<<english[(ciphertext_digital[i]-key+26)%26];
                        }
                    }
                    cout<<"\n"<<endl;
                    system("pause");
                }

            }
            if(menu_algo==2) //азбука морзе
            {
                system("cls");
                int morze_e_d;
                char morze_decoded_arr[256];
                char morze_encoded_arr[256];
                for(int l=0;l<=255;l++)
                {
                    morze_decoded_arr[l]='~';
                    morze_encoded_arr[l]='~';
                }
                cout<<"\n1. Расшифровать\n2. Зашифровать";
                cin>>morze_e_d;
                if(morze_e_d==1) //decoding
                {
                    system("cls");
                    int morze_d=2000,k=0; //k - счетчик для массива расшифрованной строки
                    while(morze_d!=0)
                    {
                        if(k<256) k++;
                        system("cls");
                        cout<<"\n\tВведите по одному номера строк, которые совпадают с зашифрованными \n\tбуквами в вашем тексте, 0 - окончание ввода..."<<endl;
                        cout<<" 1 A: ._\n 2 B: _...\n 3 C: _._.\n 4 D: _..\n 5 E: .\n 6 F: .._.\n 7 G: _ _.\n 8 H: ....\n 9 I: ..\n10 J: ._ _ _";
                        cout<<"\n11 K: _._\n12 L: ._..\n13 M: _ _\n14 N: _.\n15 O: _ _ _\n16 P: ._ _.\n17 Q: _ _._\n18 R: ._.\n19 S: ...\n20 T: _\n21 U: .._\n22 V: ..._\n23 W: ._ _\n24 X: _.._\n25 Y: _._ _\n26 Z: _ _..\n27. Пробел"<<endl;
                        cout<<"Для выхода введите -1...";
                        cin>>morze_d;
                        if((morze_d>0) and (morze_d<28))
                        {
                            if(morze_d==1) morze_decoded_arr[k-1]='A';
                            if(morze_d==2) morze_decoded_arr[k-1]='B';
                            if(morze_d==3) morze_decoded_arr[k-1]='C';
                            if(morze_d==4) morze_decoded_arr[k-1]='D';
                            if(morze_d==5) morze_decoded_arr[k-1]='E';
                            if(morze_d==6) morze_decoded_arr[k-1]='F';
                            if(morze_d==7) morze_decoded_arr[k-1]='G';
                            if(morze_d==8) morze_decoded_arr[k-1]='H';
                            if(morze_d==9) morze_decoded_arr[k-1]='I';
                            if(morze_d==10) morze_decoded_arr[k-1]='J';
                            if(morze_d==11) morze_decoded_arr[k-1]='K';
                            if(morze_d==12) morze_decoded_arr[k-1]='L';
                            if(morze_d==13) morze_decoded_arr[k-1]='M';
                            if(morze_d==14) morze_decoded_arr[k-1]='N';
                            if(morze_d==15) morze_decoded_arr[k-1]='O';
                            if(morze_d==16) morze_decoded_arr[k-1]='P';
                            if(morze_d==17) morze_decoded_arr[k-1]='Q';
                            if(morze_d==18) morze_decoded_arr[k-1]='R';
                            if(morze_d==19) morze_decoded_arr[k-1]='S';
                            if(morze_d==20) morze_decoded_arr[k-1]='T';
                            if(morze_d==21) morze_decoded_arr[k-1]='U';
                            if(morze_d==22) morze_decoded_arr[k-1]='V';
                            if(morze_d==23) morze_decoded_arr[k-1]='W';
                            if(morze_d==24) morze_decoded_arr[k-1]='X';
                            if(morze_d==25) morze_decoded_arr[k-1]='Y';
                            if(morze_d==26) morze_decoded_arr[k-1]='Z';
                            if(morze_d==27) morze_decoded_arr[k-1]=' ';
                        }
                        else
                        {
                            if(morze_d==-1) goto metka_menu;
                        }

                    } //конец while
                    cout<<"\n\nРасшифрованное сообщение: ";
                    char morze_navigate;
                    for(int l=0;l<=255;l++)
                    {
                        if(morze_decoded_arr[l]!='~') cout<<morze_decoded_arr[l];
                    }
                    cout<<"\n\n\t\t\tBackspace - назад\n\t\t\tEnter - выход"<<endl;
                    morze_navigate=getch();
                    if(morze_navigate==8) goto metka_menu;
                }
                if(morze_e_d==2) //encoding
                {
                    cout<<"\n\tВведите сообщение(ОКОНЧАНИЕ СТРОКИ - #): ";
                    int m_c=0;
                    char c='~';
                    while(c!='#')
                    {
                        cin>>c;
                        if(m_c<255) m_c++;
                        morze_encoded_arr[m_c]=c;
                    }
                    system("cls");
                    cout<<"\n\n\tТекст:";
                    for(int l=0;l<=255;l++)
                    {
                        if((morze_encoded_arr[l]!='~') and (morze_encoded_arr[l]!='#')) cout<<morze_encoded_arr[l];
                    }
                    cout<<"\n\n\tЗашифрованное сообщение:\n"<<endl;
                    for(int l=0;l<=255;l++)
                    {
                        if((morze_encoded_arr[l]=='a') or (morze_encoded_arr[l]=='A')) cout<<"._  ";
                        if((morze_encoded_arr[l]=='b') or (morze_encoded_arr[l]=='B')) cout<<"_...  ";
                        if((morze_encoded_arr[l]=='c') or (morze_encoded_arr[l]=='C')) cout<<"_._.  ";
                        if((morze_encoded_arr[l]=='d') or (morze_encoded_arr[l]=='D')) cout<<"_..  ";
                        if((morze_encoded_arr[l]=='e') or (morze_encoded_arr[l]=='E')) cout<<".  ";
                        if((morze_encoded_arr[l]=='f') or (morze_encoded_arr[l]=='F')) cout<<".._.  ";
                        if((morze_encoded_arr[l]=='g') or (morze_encoded_arr[l]=='G')) cout<<"_ _.  ";
                        if((morze_encoded_arr[l]=='h') or (morze_encoded_arr[l]=='H')) cout<<"....  ";
                        if((morze_encoded_arr[l]=='i') or (morze_encoded_arr[l]=='I')) cout<<"..  ";
                        if((morze_encoded_arr[l]=='j') or (morze_encoded_arr[l]=='J')) cout<<"._ _ _  ";
                        if((morze_encoded_arr[l]=='k') or (morze_encoded_arr[l]=='K')) cout<<"_._  ";
                        if((morze_encoded_arr[l]=='l') or (morze_encoded_arr[l]=='L')) cout<<"._..  ";
                        if((morze_encoded_arr[l]=='m') or (morze_encoded_arr[l]=='M')) cout<<"_ _  ";
                        if((morze_encoded_arr[l]=='n') or (morze_encoded_arr[l]=='N')) cout<<"_.  ";
                        if((morze_encoded_arr[l]=='o') or (morze_encoded_arr[l]=='O')) cout<<"_ _ _  ";
                        if((morze_encoded_arr[l]=='p') or (morze_encoded_arr[l]=='P')) cout<<"._ _.  ";
                        if((morze_encoded_arr[l]=='q') or (morze_encoded_arr[l]=='Q')) cout<<"_ _._  ";
                        if((morze_encoded_arr[l]=='r') or (morze_encoded_arr[l]=='R')) cout<<"._.  ";
                        if((morze_encoded_arr[l]=='s') or (morze_encoded_arr[l]=='S')) cout<<"...  ";
                        if((morze_encoded_arr[l]=='t') or (morze_encoded_arr[l]=='T')) cout<<"_  ";
                        if((morze_encoded_arr[l]=='u') or (morze_encoded_arr[l]=='U')) cout<<".._  ";
                        if((morze_encoded_arr[l]=='v') or (morze_encoded_arr[l]=='V')) cout<<"..._  ";
                        if((morze_encoded_arr[l]=='w') or (morze_encoded_arr[l]=='W')) cout<<"._ _  ";
                        if((morze_encoded_arr[l]=='x') or (morze_encoded_arr[l]=='X')) cout<<"_.._  ";
                        if((morze_encoded_arr[l]=='y') or (morze_encoded_arr[l]=='Y')) cout<<"_._ _  ";
                        if((morze_encoded_arr[l]=='z') or (morze_encoded_arr[l]=='Z')) cout<<"_ _..  ";
                    }
                    cout<<"\n\n"<<endl;
                }
            }
            if(menu_algo==3) // Гронсфельд
            {
            }
            if(menu_algo==4) // Цифровые
            {
                system("cls");
                int int_arr[256];
                for(int l=0;l<=255;l++) int_arr[l]=-3;
                char rus_alph[34]={'~','А','Б','В','Г','Д','Е','Ё','Ж','З','И','Й','К','Л','М','Н','О','П','Р','С','Т','У','Ф','Х','Ц','Ч','Ш','Щ','Ъ','Ы','Ь','Э','Ю','Я'};
                char eng_alph[27]={'~','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','u','V','W','X','Y','Z'};
                cout<<"\n\n\tВведите цифры через пробел(-1 для окончания ввода): "<<endl;
                int d_c=0;
                for(int l=0;l<=255&&d_c!=-1;l++)
                {
                    cin>>d_c;
                    int_arr[l]=d_c;
                }
                cout<<"\n\nРусский алфавит: ";
                for(int l=0;l<=255;l++)
                {
                    if((int_arr[l]!=-3) and (int_arr[l]>0) and (int_arr[l]<34)) cout<<rus_alph[int_arr[l]]<<" ";
                }
                cout<<"\n\n\n\nАнглийский алфавит: ";
                for(int l=0;l<=255;l++)
                {
                    if((int_arr[l]!=-3) and (int_arr[l]>0) and (int_arr[l]<27)) cout<<eng_alph[int_arr[l]]<<" ";
                }
                cout<<"\n\n"<<endl;
                int digit_navigate;
                cout<<"\n\t\t\t-1 - назад\n\t\t\t0 - выход";
                cin>>digit_navigate;
                if(digit_navigate==-1) goto metka_error;
            }
            if(menu_algo==5) // Атбаш
            {
            }
            if(menu_algo==6) // Вертикальная перестановка
            {
                goto metka_error;
            }
            if(menu_algo==7) // Бэкон
            {
            }
            if(menu_algo==8) // Вижинер
            {
                goto metka_error;
            }
            if(menu_algo==9) // Частотный
            {
                goto metka_error;
            }
            if(menu_algo==10) // Клавиатурная
            {
            }
            if(menu_algo==11) // ASCII
            {
            }
            if(menu_algo==12) //Солитер
            {
            }
        }
        if(flag=='2') //алгоритм не известен
        {
            goto metka_error;
        }
    }
    if(menu=='2') //справка
    {
        help_menu_list: //метка списка алгоритмов в справочнике
        system("cls");
        cout<<"1. Шифр Цезаря\n\n2. Азбука Морзе\n\n3. Шифр Гронсфельда\n\n4. Цифровые шифры\n\n5. Атбаш(шифр замены)"<<endl;
        cout<<"\n6. Вертикальная перестановка\n\n7. Шифр Бэкона"<<endl;
        cout<<"\n8. Шифр Вижинера\n\n9. Частотный анализ\n\n10. Клавиатурная шифровка\n\n11. ASCII оцифровка\n\n12. Солитер"<<endl;
        cout<<"\n\n\t\t0 - назад\n\n\t\t-1 - выход..."<<endl;
        cin>>menu_help;//решить: getch или cin, с cin'ом непонятно как вернуться назад
        if(menu_help==1)
        {
            system("cls");
            cout<<"\n\n1. Шифр Цезаря - элементарный шифр сдвига с задаваемым ключом."<<endl;
            cout<<"\tТо есть представляет собой шифр, при применении которого, каждая буква"<<endl;
            cout<<"\tшифруемого текста сдвигается по алфавиту вперед или назад на заданное "<<endl;
            cout<<"\tключом кол-во позиций.\n\nПример: \n\nКлюч: 2 \nАлфавит: русский(без ё,й) \nИсходный текст: Адам\nНаправление сдвига: Вправо"<<endl;
            cout<<"\nА(+2)=>В\nд(+2)=>ж\nа(+2)=>в\nм(+2)=>о\nАдам=>Вжво"<<endl;
            cout<<"\nВыполняет элементарное условие любого шифра - довести исходный текст \nдо неузнаваемого вида."<<endl;
            cout<<"\n\n\t\tBackspace - назад\n\n\t\tEsc - выход..."<<endl;
            navigate=getch();
            if(navigate==8) goto help_menu_list;
        }
        if(menu_help==2)
        {
            system("cls");
            cout<<"\n\n2. Азбука Морзе(Морзянка) - система кодирования информации адаптированная для \n\tконвертирования текста в звуковой сигнал."<<endl;
            cout<<"\tБуквы закодированы последовательностью точек(короткий сигнал) и\n\tтире(длинный сигнал). Расшифровка происходит по международной таблице \n\tМорзе, так что шифром по сути это не является."<<endl;
            cout<<"\n\nПример: \n\nАлфавит: английский\nИсходный текст: apple\nЗашифрованный текст: .- .--. .--. .-.. .\n"<<endl;
            cout<<""<<endl;
            cout<<""<<endl;
            cout<<"\n\n\t\tBackspace - переход назад \n\n\t\tEsc - выход..."<<endl;
            navigate=getch();
            if(navigate==8) goto help_menu_list;
        }
        if(menu_help==3)
        {
            system("cls");
            cout<<"\n\n3. Шифр Гронсфельда - по сути это усложненный шифр сдвига Цезаря, разница"<<endl;
            cout<<"\tлишь в том, что ключ имеет длину сообщения или циклично записывается \n\tпо длине текста."<<endl;
            cout<<"\n\nПример: \n\nКлюч: 134276 \nАлфавит: русский(без ё,й)\nИсходный текст: Привет\n\nП(+1)=>Р\nр(+3)=>у\nи(+4)=>н\nв(+2)=>д\nе(+7)=>н\nт(+6)=>ш\nПривет=>Рунднш"<<endl;
            cout<<"\n\n\t\tBackspace - переход назад \n\n\t\tEsc - выход..."<<endl;
            navigate=getch();
            if(navigate==8) goto help_menu_list;
        }
        if(menu_help==4)
        {
            system("cls");
            cout<<"\n\n4. Цифровые шифры - от банальной оцифровки букв по порядку в алфавите, \n\tдо использования таблиц с пронумерованными строками и столбцами"<<endl;
            cout<<"\nПример: "<<endl;
            cout<<"\nАлфавит: русский(без ё,й; нумерация с 0)"<<endl;
            cout<<"Исходный текст: Чистый"<<endl;
            cout<<"Ч - 22"<<endl;
            cout<<"и - 8"<<endl;
            cout<<"с - 16"<<endl;
            cout<<"т - 17"<<endl;
            cout<<"ы - 26"<<endl;
            cout<<"и(й) - 8"<<endl;
            cout<<"Чистый=>22 8 16 17 26 8"<<endl;
            cout<<"\n\n\t\tBackspace - переход назад \n\n\t\tEsc - выход..."<<endl;
            navigate=getch();
            if(navigate==8) goto help_menu_list;
        }
        if(menu_help==5)
        {
            system("cls");
            cout<<"\n\n5. Атбаш - простой шифр замены, выделился лишь исторически. Этот шифр \n\tприменялся к текстам на еврейском. Для первой буквы используется \n\tпоследняя, для второй - предпоследняя и т.д:А=>Я, Б=>Ю"<<endl;
            cout<<"\nА Б В Г Д Е Ж З И К Л М Н О П Р С Т У Ф Х Ц Ч Ш Щ Ъ Ы Ь Э Ю Я"<<endl;
            cout<<"Я Ю Э Ь Ы Ъ Щ Ш Ч Ц Х Ф У Т С Р П О Н М Л К И З Ж Е Д Г В Б А"<<endl;
            cout<<"\nПример:"<<endl;
            cout<<"Алфавит: русский(без ё,й)"<<endl;
            cout<<"Исходный текст: Лукошко"<<endl;
            cout<<"Л=>Х"<<endl;
            cout<<"у=>н"<<endl;
            cout<<"к=>ц"<<endl;
            cout<<"о=>т"<<endl;
            cout<<"ш=>з"<<endl;
            cout<<"к=>ц"<<endl;
            cout<<"о=>т"<<endl;
            cout<<"Лукошко=>Хнцтзцт"<<endl;
            cout<<"\n\n\t\tBackspace - переход назад \n\n\t\tEsc - выход..."<<endl;
            navigate=getch();
            if(navigate==8) goto help_menu_list;
        }
        if(menu_help==6)
        {
            system("cls");
            cout<<"\n\n6. Вертикальная перестановка с ключом. Суть вертикальной перестановки - \n\tзаписать текст в таблицу AxB слева направо. Зашифрованный текст - \n\tнабор вертикально прочитанных из таблицы слов. Ключ - порядок, в \n\tкотором надо считывать вертикали."<<endl;
            cout<<"\nПример:"<<endl;
            cout<<"\n\nКлюч: 14253"<<endl;
            cout<<"\n\nАлфавит: русский(без ё,й)"<<endl;
            cout<<"\n"<<endl;
            cout<<"_____________________"<<endl;
            cout<<"| 1 | 4 | 2 | 5 | 3 |"<<endl;
            cout<<"---------------------"<<endl;
            cout<<"| п | р | и | в | е |"<<endl;
            cout<<"---------------------"<<endl;
            cout<<"| т | к | а | к | д |"<<endl;
            cout<<"---------------------"<<endl;
            cout<<"| е | л | а | ? | ? |"<<endl;
            cout<<"---------------------"<<endl;
            cout<<"\nЗашифрованное сообщение: \nпте(1)\nиаа(2)\nед?(3)\nркл(4)\nвк?(5)\nпте иаа ед? ркл вк?";
            cout<<"\n\n\t\tBackspace - переход назад \n\n\t\tEsc - выход..."<<endl;
            navigate=getch();
            if(navigate==8) goto help_menu_list;
        }
        if(menu_help==7)
        {
            system("cls");
            cout<<"\n\n7. Шифр Бэкона - любой алфавит, записанный в двоичном виде в пятеричной \n\tсистеме, вместо 0 и 1 можно взять А и В."<<endl;
            cout<<"\n\nПример: "<<endl;
            cout<<"_____________________________________________________________"<<endl;
            cout<<"|  a  |ААААА|  g  |ААВВА|  m  |АВВАА|  s  |ВААВА|  y  |ВВААА|"<<endl;
            cout<<"-------------------------------------------------------------"<<endl;
            cout<<"|  b  |ААААВ|  h  |ААВВВ|  n  |АВВАВ|  t  |ВААВВ|  z  |ВВААВ|"<<endl;
            cout<<"-------------------------------------------------------------"<<endl;
            cout<<"|  c  |АААВА|  i  |АВААА|  o  |АВВВА|  u  |ВАВАА|     |     |"<<endl;
            cout<<"-------------------------------------------------------------"<<endl;
            cout<<"|  d  |АААВВ|  j  |АВААВ|  p  |АВВВВ|  v  |ВАВАВ|     |     |"<<endl;
            cout<<"-------------------------------------------------------------"<<endl;
            cout<<"|  e  |ААВАА|  k  |АВАВА|  q  |ВАААА|  w  |ВАВВА|     |     |"<<endl;
            cout<<"-------------------------------------------------------------"<<endl;
            cout<<"|  f  |ААВАВ|  l  |АВАВВ|  r  |ВАААВ|  x  |ВАВВВ|     |     |"<<endl;
            cout<<"-------------------------------------------------------------"<<endl;
            cout<<"\nАлфавит: английский(нумерация с 0)"<<endl;
            cout<<"\nИсходный текст: Hi, Jack"<<endl;
            cout<<"\nААВВВ(H) \nАВААА(i) \nАВААВ(J) \nAAAAA(a) \nАААВА(с) \nABABA(k)"<<endl;
            cout<<"\nHi, Jack=>AABBB ABAAA, ABAAB AAAA AAABA ABABA"<<endl;;
            cout<<"\n\n\t\tBackspace - переход назад \n\n\t\tEsc - выход..."<<endl;
            navigate=getch();
            if(navigate==8) goto help_menu_list;
        }
        if(menu_help==8)
        {
            system("cls");
            cout<<"\n\n8. Шифр Вижинера - шифр со сдвигом для каждой буквы алфавита. Шифрование"<<endl;
            cout<<"\n\tпроисходит по таблице Вижинера. Выбирается ключ и записывается циклически, пока не"<<endl;
            cout<<"\n\tстанет равен длине шифруемого текста. Выбирается одноименная букве ключа строка и одноименный"<<endl;
            cout<<"\n\tбукве текста столбец. Пересечение выбранной строки и выбранного столбца и есть зашифрованная буква."<<endl;
            cout<<"|#|A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z|"<<endl;
            cout<<"--|---------------------------------------------------"<<endl;
            cout<<" A|A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z|"<<endl;
            cout<<"--|---------------------------------------------------"<<endl;
            cout<<" B|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z|A|"<<endl;
            cout<<"--|---------------------------------------------------"<<endl;
            cout<<" C|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z|A|B|"<<endl;
            cout<<"--|---------------------------------------------------"<<endl;
            cout<<" D|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z|A|B|C|"<<endl;
            cout<<"--|---------------------------------------------------"<<endl;
            cout<<" E|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z|A|B|C|D|"<<endl;
            cout<<"\n....и так далее..."<<endl;
            cout<<"------------------------------------------------------"<<endl;
            cout<<"\n\nПример: "<<endl;
            cout<<"\nКодовое слово(ключ): CAB"<<endl;
            cout<<"Алфавит: английский"<<endl;
            cout<<"Исходный текст: Abde(no meaning)"<<endl;
            cout<<"Запсиь ключа: \nA-C\nb-A\nd-B\ne-C\nAbde=>CABC"<<endl;
            cout<<"Зашифрованный текст: \nстолбец 'A' и  строка 'C'=> C"<<endl;
            cout<<"столбец 'b' и  строка 'A'=> B"<<endl;
            cout<<"столбец 'd' и  строка 'B'=> E"<<endl;
            cout<<"столбец 'e' и  строка 'C'=> G"<<endl;
            cout<<"слово Abde с ключом CAB => Cbeg"<<endl;
            cout<<"\n\n\t\tBackspace - переход назад \n\n\t\tEsc - выход..."<<endl;
            navigate=getch();
            if(navigate==8) goto help_menu_list;
        }
        if(menu_help==9)
        {
            system("cls");
            cout<<"\n\n9. Частотный анализ - способ, очень тесно связанный с лингвистикой. \n\tПрименяется при расшифровке текстов, зашифрованных заменой.\n\tЕго суть в том, что буквы в зашифрованном тексте сохраняют\n\tту частоту, с которой встречаются буквы нормального сообщения.\n\tДля каждого языка есть свои частотные таблицы, составляемые по\n\tклассическим текстам(произведения классиков)."<<endl;
            cout<<"\nЧастотность некоторых букв русского языка:\n"<<endl;
            cout<<"\tА -  8% (0.07998)"<<endl;
            cout<<"\n\tЛ -  4% (0.04343)"<<endl;
            cout<<"\n\tО - 11% (0.10983)"<<endl;
            cout<<"\n\tГ -  2% (0.01641)"<<endl;
            cout<<"\n\n\t\tBackspace - переход назад \n\n\t\tEsc - выход..."<<endl;
            navigate=getch();
            if(navigate==8) goto help_menu_list;
        }
        if(menu_help==10)
        {
            system("cls");
            cout<<"\n\n10. Клавиатурная шифровка - она наверняка порождена ошибкой, это самый \n\tдоступный шифр замены. Если начать набирать русский текст, забыв \n\tпереключить английскую раскладку."<<endl;
            cout<<"\nПример:"<<endl;
            cout<<"\n\tАлфавит: руссский"<<endl;
            cout<<"\tИсходный текст: карандаш"<<endl;
            cout<<"\tЗашифрованный текст: rfhfylfi"<<endl;
            cout<<"\n\n\t\tBackspace - переход назад \n\n\t\tEsc - выход..."<<endl;
            navigate=getch();
            if(navigate==8) goto help_menu_list;
        }
        if(menu_help==11)
        {
            system("cls");
            cout<<"\n\n11. ASCII оцифровка - элементарная оцифровка, производимая по \n\t'Американской Стандартной Кодировочной Таблице Печатных Символов', \n\tэто таблица, содержащая числовые коды клавиш, которые мы нажимаем."<<endl;
            cout<<"\nПример:"<<endl;
            cout<<"\n\tАлфавит: английский"<<endl;
            cout<<"\tИсходный текст: hello"<<endl;
            cout<<"\tЗашифрованный текст(десятичное представление):\n\tH=>72\n\te=>69\n\tl=>76\n\tl=>76\n\to=>79\n\tHello=> 72 69 76 76 79"<<endl;
            cout<<"\n\n\t\tBackspace - переход назад \n\n\t\tEsc - выход..."<<endl;
            navigate=getch();
            if(navigate==8) goto help_menu_list;
        }
        if(menu_help==12)
        {
            system("cls");
            cout<<"\n\n12. Солитер - поточный шифр, изобретенный Брюсом Шнайером по просьбе писателя.\n\tОцифрованные буквы исходного текста складываются с оцифрованными\n\tбуквами гаммы(кодовое слово) по модулю 26(для английского алфавита)."<<endl;
            cout<<"\n\n\t\tBackspace - переход назад \n\n\t\tEsc - выход..."<<endl;
            navigate=getch();
            if(navigate==8) goto help_menu_list;
        }
        if(menu_help==0) goto metka_menu;

    }
    if(menu=='3') //о программе
    {
        system("cls");
        cout<<"\n\tПрограмма Simple_Decipher++ поможет ознакомиться с некоторыми наиболее\n\tизвестными шифрами, расшифрует текст по алгоритмам, преусмотренным в\n\tфункционале. Также, в случае если пользователь не знает, по какому\n\tалгоритму зашифрован текст, программа предложит ввести его и,\n\tпроанализировав, выдаст все возможные варианты расшифровки."<<endl;
        cout<<"\n\n\t\tBackspace - переход назад \n\n\t\tEsc - выход..."<<endl;
        navigate=getch();
        if(navigate==8) goto metka_menu;
    }
    return 0;
}
