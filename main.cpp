#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

ifstream f("Dimensiuni1.txt");
ofstream g("Dimensiuni2.txt");

class perete
{
public:

    int inaltime, lungime;
    char tip_camera[100];

    void meniu1()
    {
        cout << "\n1.Citeste dimensiunile peretelui din fisier(inaltime,lungime)";
        cout << "\n2.Citeste dimensiunile peretelui de la tastatura";
        cout << "\n3.Afisare dimensiuni citite";
        cout << "\n4.Introduceti tipul de camera (baie,bucatarie,etc.)";
        cout << "\n5.Mergeti la urmatorul pas";
        cout << "\n6.Prinatrea datelor in fisier";
        cout << "\n0.Iesire din aplicatie";
        cout << "\nOptiunea=";
    }

    //Mai e de lucru la fstream si ofstream

    void citire_fisier()
    {
        f >> inaltime;
        f >> lungime;
    }


    void citire_tastaura()
    {
        cout << endl << "Introduceti inaltimea=";
        cin >> inaltime;
        cout << "Introduceti lungimea=";
        cin >> lungime;
        system("cls");
    }

    void afisare_dimensiuni()
    {
        cout << "\nLungimea peretelui este=" << lungime;
        cout << "\nInaltimea peretelui este=" << inaltime;
        sleep_for(seconds(3));
        system("cls");
    }

    void tip_c()
    {
        cout << "Introduceti tipul de camera=";
        cin >> tip_camera;
        system("cls");
    }
}p;

class dulap : public perete
{

public:

    struct dul
    {
        int inaltime = 0, latime = 0, adancime = 0, nr_rafturi = 0, nr_sertare = 0, nr_usi = 0, cant = -1;
    }d[100];

    int lim_d = 1;

    void citire_meniu()
    {

        int m;
        do
        {
            meniu1();
            cin >> m;
            switch (m)
            {
            case 1:
                system("cls");
                p.citire_fisier();
                break;

            case 2:
                system("cls");
                p.citire_tastaura();
                break;

            case 3:
                system("cls");
                p.afisare_dimensiuni();

                break;

            case 4:
                system("cls");
                p.tip_c();

                break;

            case 5:
                system("cls");
                citire_meniu2();

                break;

            }

        } while (m != 0);

    }

    void meniu2()
    {
        cout << "\n======================================";
        cout << "\n1.Adaugati un dulap nou";
        cout << "\n2.Preseturi dulap";
        cout << "\n3.Introducere numar de rafturi";
        cout << "\n4.Introducere numar sertare(2 sau 3)";
        cout << "\n5.Introducere numar usi";
        cout << "\n6.Introduceti dimensiunile dulapului si cant";
        cout << "\n7.Reeditarea datelor unui dulap";
        cout << "\n8.Afisare date dulapuri";
        cout << "\n9.Calcularea dimensiunilor";
        cout << "\n10.Scrierea dimensiunilor in fisier";
        cout << "\n0.Inapoi la meniul principal";
        cout << "\nOptiunea=";
    }

    void citire_meniu2()
    {
        int m;

        do
        {

            meniu2();
            cin >> m;
            switch (m)
            {
            case 1:
                system("cls");
                dulap_nou();

                break;

            case 2:
                system("cls");
                citire_meniu_preset();

                break;

            case 3:
                system("cls");
                nr_rafturi();
                break;

            case 4:
                system("cls");
                nr_sertare();
                break;

            case 5:
                system("cls");
                nr_usi();
                break;

            case 6:
                system("cls");
                citire_dimensiuni_si_cant();
                break;

            case 7:
                system("cls");
                reeditare_dulap();
                break;

            case 8:
                system("cls");
                afisare_dulap();
                system("cls");
                break;

            case 9:
                system("cls");
                calculare();
                break;

            case 10:
                system("cls");
                scriere_dimensiuni_fisier();
                break;

            }

        } while (m != 0);
        system("cls");


    }


    void v_latime_perete()
    {
        int suma_lat = 0;
        for (int i = 1; i <= lim_d; ++i)
        {
            suma_lat += d[lim_d].latime;
        }
        if (suma_lat > p.lungime)
        {
            int choice;
            cout << "\nLatimea corpurilor adunate depaseste latimea peretelui. Doriti sa reeditati ultimul corp?" << endl << "1.Da" << endl << "2.Nu" << "\nOptiunea=";
            cin >> choice;
            if (choice == 1)
            {
                system("cls");
                reeditare_dulap();
            }

        }
        system("cls");

    }


    void dulap_nou()
    {
        int choice = 0;

        if (lim_d != 0 && d[lim_d].inaltime == 0 && d[lim_d].latime == 0)
        {
            cout << "\nNu ati modificat parametri dulapului anterior. Doriti sa continuati?" << endl << "1.Da" << endl << "2.Nu" << "\nOptiunea=";
            cin >> choice;
            if (choice == 2)
            {
                system("cls");
                citire_meniu2();
            }
        }
        else
        {
            choice = 0;
            if (ok_calculare == 0)
            {
                cout << "\nNu ati calculat dimensiunile pentru dulapul anterior. Doriti sa continuati?" << "\n1.Da" << "\n2.Nu" << "\nOptiunea=";
                cin >> choice;
                if (choice == 2)
                {
                    system("cls");
                    citire_meniu2();
                }
            }
        }
        if (p.inaltime < d[lim_d].inaltime)
        {
            cout << p.inaltime;
            cout << "\nInaltimea dulapului depaseste inaltimea peretelui. Doriti sa reeditati dimensiunile dulapului?" << "\n1.Da" << "\n2.Nu" << "\nOptiunea=";
            cin >> choice;
            if (choice == 1)
            {
                system("cls");
                reeditare_dulap();
            }

        }


        v_latime_perete();
        system("cls");

        lim_d++;

        cout << "\n======================================";
        cout << "\n            Un dulap nou a fost adaugat";
        cout << "\n======================================";
        sleep_for(seconds(3));

        system("cls");
        ok_calculare = 0;

    }

    void nr_rafturi()
    {
        cout << "\nIntroduceti numarul de rafturi=";
        cin >> d[lim_d].nr_rafturi;
        system("cls");
        citire_meniu2();
    }

    void nr_sertare()
    {
        cout << "\nIntroduceti numarul de sertare=";
        cin >> d[lim_d].nr_sertare;
        system("cls");
        meniu_tip_sertare();

    }

    void nr_usi()
    {
        //Trebuie sa vezi unde vin plasate usile
        cout << "\nIntroduceti numarul de usi=";
        cin >> d[lim_d].nr_usi;
        system("cls");
    }
    void citire_dimensiuni_si_cant()
    {
        cout << "\nIntroduceti inaltimea dulapului=";
        cin >> d[lim_d].inaltime;
        cout << "\nIntroduceti latimea dulapului=";
        cin >> d[lim_d].latime;
        cout << "\n Introduceti adancimea dulapului=";
        cin >> d[lim_d].adancime;
        cant_corp();

    }
    void meniu_reeditare()
    {

        cout << "\n1.Modificare inaltime";
        cout << "\n2.Modificare latime";
        cout << "\n0.Intoarcere la configurarea dulapului ";
        cout << "\nOptiunea=";

    }
    void reeditare_dulap()
    {
        int n;
        do
        {
            meniu_reeditare();
            cin >> n;
            switch (n)
            {
            case 1:
            {
                cout << "\nIntroduceti inaltimea dulapului=";
                cin >> d[lim_d].inaltime;
            }
            case 2:
            {
                cout << "\nIntroduceti latimea dulapului=";
                cin >> d[lim_d].latime;
            }
            case 0:
            {
                citire_meniu2();
            }
            }
        } while (n != 0);


    }

    void meniu_cant()
    {
        cout << "\nAlegeti optiunea de cant pentru usi/sertare";
        cout << "\n1.Cant 0.8";
        cout << "\n2.Cant 2";
        cout << "\nOptiune=";
    }

    void cant_corp()
    {
        int choice;
        meniu_cant();
        cin >> choice;
        if (choice == 1)
            d[lim_d].cant = 1;
        else
            d[lim_d].cant = 2;
        system("cls");

    }
    void afisare_dulap()
    {
        for (int i = 1; i <= lim_d; ++i)
        {
            cout << "\nDulapul " << i << " are urmatoarele caracteristici:";
            cout << "\nNumarul de usi=" << d[i].nr_usi;
            cout << "\nNumarul de rafturi=" << d[i].nr_rafturi;
            cout << "\n Numarul de sertare=" << d[i].nr_sertare;
            cout << "\nInaltimea dulapului este=" << d[i].inaltime;
            cout << endl;
        }
        system("pause");
    }


    //adaugare_dim o sa fie folosit dupa calcularea dimensiunilor pentru adaugarea in lista


    // adnacime corpuri jos 560 inaltime 760 latime 600
    // adancime corpuri sus 320  inaltime 900(laterala)

    //coloana 3 de la lista dimensiuni reprezinta tipul de ...

    //Prelucrarea dimensiunilor

    long long lista_dimensiuni[1000][4] = { { 0 } };
    int nr_dimensiuni = 0;
    int cant = -1;




    void adaugare_dim(int lungime, int latime, int bucati)
    {
        int valoarea_exista = 0;

        for (int i = 1; i <= nr_dimensiuni && valoarea_exista == 0; ++i)
        {
            if (lungime == lista_dimensiuni[i][1] && latime == lista_dimensiuni[i][2])

            {

                lista_dimensiuni[i][3] += bucati;
                valoarea_exista = 1;
            }
        }
        if (valoarea_exista == 0)
        {

            lista_dimensiuni[++nr_dimensiuni][1] = lungime;
            lista_dimensiuni[nr_dimensiuni][2] = latime;
            lista_dimensiuni[nr_dimensiuni][3] = bucati;
            //nr_dimensiuni++;

        }


    }

    //preseturi

    void meniu_preseturi()
    {
        cout << "\n1.Corp mobila standard jos";
        cout << "\n2.Corp mobila standard sus";
        cout << "\n0.Intoarcere la meniul de dulapuri";
        cout << "\nOptiunea=";
    }
    void citire_meniu_preset()
    {
        int choice;
        do
        {
            cant_corp();
            system("cls");
            meniu_preseturi();
            cin >> choice;

            switch (choice)
            {
            case 1:
                corp_jos();
                choice = 0;
                break;
            case 2:
                corp_sus();
                choice = 0;
                break;
            }
        } while (choice != 0);
        system("cls");
        citire_meniu2();
    }



    void corp_masina_spalat_vase_incorp()
    {

    }

    //frigider incorporat

    void atribuire_mesaj()
    {
        system("cls");
        cout << "\n======================================";
        cout << "\n            Dimensiunile au fost atribuite";
        cout << "\n======================================";



    }

    void corp_jos()
    {
        d[lim_d].latime = 600;
        d[lim_d].inaltime = 760;
        d[lim_d].adancime = 560;
        atribuire_mesaj();
        sleep_for(seconds(3));
        system("cls");
    }
    void corp_sus()
    {
        d[lim_d].latime = 600;
        d[lim_d].inaltime = 900;
        d[lim_d].adancime = 320;
        atribuire_mesaj();
        sleep_for(seconds(3));
        system("cls");
    }

    /// <summary>
    /// Fete corp
    /// cant 0.8
    /// cant 2
    /// cant de 2 scazi 7 mm si la cantul de 0.8 scazi 5 mm
    /// </summary>



    //copr 2 usi trebuie scazut latimea-6 si dupa /2 -cant -1

    void usa_corp()
    {
        if (d[lim_d].nr_sertare == 0 && d[lim_d].nr_usi == 1)
        {
            if (d[lim_d].cant == 1)
                adaugare_dim(d[lim_d].inaltime - 5, d[lim_d].latime - 5, 1);
            else
                adaugare_dim(d[lim_d].inaltime - 7, d[lim_d].latime - 7, 1);
        }
        if (d[lim_d].nr_sertare == 0 && d[lim_d].nr_usi == 2)
        {
            if (d[lim_d].cant == 1)
                adaugare_dim(d[lim_d].inaltime - 5, (d[lim_d].latime - 6) / 2 - d[lim_d].cant - 1, 2);
            else
                adaugare_dim(d[lim_d].inaltime - 7, (d[lim_d].latime - 6) / 2 - d[lim_d].cant - 1, 2);
        }
        cout << "\n======================================";
        cout << "\n       Fata corpului a fost adaugata in lista de dimensiuni";
        cout << "\n======================================";
        sleep_for(seconds(3));
        system("cls");
    }


    /// <summary>
    /// Sertare
    /// 10mm scazi(spatiu intre sertare)
    /// cant 2 122 247 372 latime 593
    /// cant 1 124 249 374
    /// </summary>

    void meniu_tip_sertare()
    {
        sertare_egale = 0;
        cout << "\nCe tip de sertare doriti?";
        cout << "\n1.Egale";
        cout << "\n0.Pe 3 dimensiuni(mic,mediu,mare)";
        cout << "\nOptiunea=";
        cin >> sertare_egale;
        system("cls");


    }

    int ok_calculare = 0, sertare_egale;

    void calculare()
    {
        if (ok_calculare == 1)
        {
            cout << "\n======================================";
            cout << "\nAcest corp a fost deja calculat";
            cout << "\n======================================";
            sleep_for(seconds(3));
            system("cls");
        }
        else
        {
            ok_calculare = 1;
            //calcularea marginilor corpului

            //lateralele
            adaugare_dim(d[lim_d].inaltime, d[lim_d].adancime, 2);

            //capac
            adaugare_dim(d[lim_d].latime - 36, d[lim_d].adancime, 2);

            if (d[lim_d].nr_rafturi != 0)
            {
                cout << "\nCalcualare rafturi...";
                adaugare_dim(d[lim_d].latime - 37, d[lim_d].adancime - 10, d[lim_d].nr_rafturi);
                cout << "\n*Rafturile au fost calculate si adaugate*";
                sleep_for(seconds(3));
                system("cls");
            }
            if (d[lim_d].nr_sertare != 0)
            {
                if (d[lim_d].nr_sertare >= 2 && sertare_egale == 1)
                {
                    cout << "\nCalcualare sertare...";
                    adaugare_dim(((d[lim_d].inaltime - 3 * d[lim_d].nr_sertare) - 2 * d[lim_d].nr_sertare * d[lim_d].cant) / d[lim_d].nr_sertare, d[lim_d].latime - 2 * d[lim_d].cant, d[lim_d].nr_sertare);
                    cout << "\n*Sertarele au fost calculate si adaugate*";
                }
                if (sertare_egale == 0 && d[lim_d].nr_sertare == 3)
                {
                    cout << "\nCalcualare sertare...";
                    adaugare_dim(d[lim_d].inaltime / 2 - 2 * d[lim_d].cant - 3, d[lim_d].latime - 2 * d[lim_d].cant, 1);
                    adaugare_dim(((d[lim_d].inaltime / 2) / 3) * 2 - 2 * d[lim_d].cant, d[lim_d].latime - 2 * d[lim_d].cant, 1);
                    adaugare_dim(((d[lim_d].inaltime / 2) / 3) - 2 * d[lim_d].cant, d[lim_d].latime - 2 * d[lim_d].cant, 1);
                    cout << "\n*Sertarele au fost calculate si adaugate*";
                }

            }
            usa_corp();
        }
    }

    void scriere_dimensiuni_fisier()
    {
        if (lim_d == 0)
        {
            cout << "\nNu aveti nici un dulap creat pentru a scrie date in fisier";
            sleep_for(seconds(3));
            system("cls");
            citire_meniu2();
        }
        else
        {
            bool scriere = false;
            for (int i = 1; i <= nr_dimensiuni; i++)
            {
                scriere = true;
                g << endl;
                g << lista_dimensiuni[i][1] << ' ' << lista_dimensiuni[i][2] << ' ' << lista_dimensiuni[i][3] << " buc";
            }
            if (scriere == true)
            {
                cout << "\n======================================";
                cout << "\n            Dimensiunile au fost scrise";
                cout << "\n======================================";
                sleep_for(seconds(3));
                system("cls");
            }
            else
            {
                cout << "\n======================================";
                cout << "\n            Dimensiunile nu au fost scrise";
                cout << "\n======================================";
                sleep_for(seconds(3));
                system("cls");
            }
        }
    }

    /// <summary>
    /// polite latime -1mm si -10mm in adancime
    /// </summary>


};


int main()
{
    dulap dul;
    dul.citire_meniu();
    f.close();
    return 0;
}
