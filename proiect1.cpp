#include <iostream>
#include <vector>
#include <list>
//#include <fstream>
//std::ifstream in("in.txt");

class Day {
private:
    const std::string name;
    std::list<std::string> movies;
public:
    Day(const std::string name) : name{name} { movies = {}; }

    void addMovie(const std::vector<std::string> movieNames) {
        for (auto i: movieNames)
            movies.push_back(i);
    }

    const std::list<std::string> getMovies() { return movies; }

    const std::string getName() const { return name; }

    int movieAvailability(int filmIndex) {
        if (filmIndex > movies.size()) {
            return 0;
        } else {
            return 1;
        }
    }
};

class Movie {
private:
    const std::string name;
    std::vector<std::string> hours;
    std::string description;

    int checkHour(std::string hour) {
        for (auto i: hours)
            if (hour == i)
                return 1;
        return 0;
    }

public:
    Movie(const std::string name) : name{name} {
        hours = {};
        description = "";
    }

    void addHour(std::vector<std::string> ore) {
        for (auto i: ore)
            hours.push_back(i);
    }

    void showHours() {
        std::cout << "|";
        for (const auto &hour: hours) {
            std::cout << hour << "|";
        }
    }

    std::vector<std::string> getHours() const { return hours; }

    const std::string getName() const { return name; }

    void addInfo(const std::string description) { this->description = description; }

    std::string getInfo() const { return description; }

    int hourAvailability(std::string oraAleasa) {
        for (int i = 0; i <= hours.size(); i++) {
            if (oraAleasa == hours[i]) {
                return 1;
            }
        }
        return 0;
    }

    friend class Cinema;
};

class Cinema {
private:
    const std::string name;
    std::vector<std::string> movies;
    std::vector<int> seats = {};

public:
    Cinema(const std::string name) : name{name} {}

    void addMovies(std::vector<Movie> m, std::vector<std::string> h) {
        for (int i = 0; i < m.size(); i++)
            for (int j = 0; j < h.size(); j++)
                if (m[i].checkHour(h[j]) == 1) {
                    movies.push_back(m[i].getName() + "-" + h[j]);
                    seats.push_back(40);
                }
    }

    int getAvailableSeats(std::string m) {
        for (int i = 0; i < movies.size(); i++)
            if (movies[i] == m)
                return seats[i];

    }

    int occupySeats(Movie movie, std::string hour, int number_of_seats) {
        int counter = -1;
        for (int cnt = 0; cnt < movies.size(); cnt++) {
            if (movies[cnt] == movie.getName() + "-" + hour) {
                if (seats[cnt] >= number_of_seats) {
                    seats[cnt] -= number_of_seats;
                    counter = cnt;
                    break;
                }
            }
        }
        if (counter < 0) {
            return 0;
        } else return 1;
    }

    std::string getName() const { return name; }

    std::vector<std::string> getMovies() const { return movies; }

};

class Profile {
private:
    const std::string name;
    const std::string password;
    std::vector<std::vector<std::string>> reservations;
public:
    Profile(const std::string name, std::string password) : name{name}, password{password} { reservations = {}; }

    void newReservation(std::string zi, std::string film, std::string ora, std::string salacinema, std::string nrloc) {
        reservations.push_back({zi, film, ora, salacinema, nrloc});
    }

    int checkProfile(const std::string nume, std::string parola) {
        if (parola == password && nume == name)
            return 1;
        else if (password != parola && name == nume)
            return 0;
        else if (nume != name)
            return -1;
    }

    const std::string getName() const { return name; }

    friend std::ostream &operator<<(std::ostream &os, const Profile &profile);
};

std::ostream &operator<<(std::ostream &os, const Profile &profile) {
    int cnt = 0;
    os << "Afisam rezervarile profilului cu numele " << profile.getName() << ":" << std::endl;
    for (auto it = profile.reservations.begin(); it != profile.reservations.end(); it++) {
        std::vector<std::string> rez = *it;
        std::cout << "Ziua: " << rez[0] << std::endl;
        std::cout << "Filmul: " << rez[1] << std::endl;
        std::cout << "Ora: " << rez[2] << std::endl;
        std::cout << "Sala: " << rez[3] << std::endl;
        std::cout << "Numar de locuri: " << rez[4] << std::endl << std::endl;
    }
    return os;
}


void setDays(std::vector<Day> &zile) {

    Day Luni("luni");
    Day Marti("marti");
    Day Miercuri("miercuri");
    Day Joi("joi");
    Day Vineri("vineri");
    Day Sambata("sambata");
    Day Duminica("duminica");

    Luni.addMovie({"2020", "Baghead:Mesagerul Mortii", "Baietii buni ajung in rai", "Kung Fu Panda 4", "Camera Rosie",
                   "Casatoriti din greseala", "Dune:Partea II", "Eu capitan"});
    Marti.addMovie({"2020", "Baghead:Mesagerul Mortii", "Baietii buni ajung in rai", "Kung Fu Panda 4", "Camera Rosie",
                    "Casatoriti din greseala", "Dune:Partea II", "Eu capitan", "Madame Web", "Demonul copilariei"});
    Miercuri.addMovie({"Baghead:Mesagerul Mortii", "Baietii buni ajung in rai", "Kung Fu Panda 4", "Camera Rosie",
                       "Casatoriti din greseala", "Dune:Partea II", "Eu capitan", "Madame Web", "Demonul copilariei"});
    Joi.addMovie({"Baghead:Mesagerul Mortii", "Baietii buni ajung in rai", "Kung Fu Panda 4", "Camera Rosie",
                  "Casatoriti din greseala", "Dune:Partea II", "Eu capitan", "Madame Web", "Demonul copilariei"});
    Vineri.addMovie(
            {"Kung Fu Panda 4", "Camera Rosie", "Casatoriti din greseala", "Dune:Partea II", "Eu capitan", "Madame Web",
             "Demonul copilariei", "Fantomele trecutului", "Gheara de fier", "Imaculata"});
    Sambata.addMovie(
            {"Kung Fu Panda 4", "Camera Rosie", "Casatoriti din greseala", "Dune:Partea II", "Eu capitan", "Madame Web",
             "Demonul copilariei", "Fantomele trecutului", "Gheara de fier", "Imaculata"});
    Duminica.addMovie(
            {"Kung Fu Panda 4", "Camera Rosie", "Casatoriti din greseala", "Dune:Partea II", "Eu capitan", "Madame Web",
             "Demonul copilariei", "Fantomele trecutului", "Gheara de fier", "Imaculata"});

    zile.push_back(Luni);
    zile.push_back(Marti);
    zile.push_back(Miercuri);
    zile.push_back(Joi);
    zile.push_back(Vineri);
    zile.push_back(Sambata);
    zile.push_back(Duminica);

}

void setMovies(std::vector<Movie> &filme, std::vector<Cinema> &sali) {

    Movie m1("2020");
    Movie m2("Baghead:Mesagerul Mortii");
    Movie m3("Baietii buni ajung in rai");
    Movie m4("Kung Fu Panda 4");
    Movie m5("Camera Rosie");
    Movie m6("Casatoriti din greseala");
    Movie m7("Dune:Partea II");
    Movie m8("Eu capitan");
    Movie m9("Madame Web");
    Movie m10("Demonul copilariei");
    Movie m11("Fantomele trecutului");
    Movie m12("Gheara de fier");
    Movie m13("Imaculata");

    m1.addInfo(
            "TITLU ORIGINAL: 2020 2D\nGENUL FILMULUI: Comedie, Drama\nDISTRIBUTIE: Silviu Geamanu, Puiu Mircea Lascus, Simona Maicanescu\nREGIZOR: Bobby Barbacioru\nPRODUCTIE: 2023\n\n");
    m2.addInfo(
            "TITLU ORIGINAL: Baghead 2D\nGENUL FILMULUI: Horror\nDISTRIBUTIE: Freya Allan, Peter Mullan, Saffron Burrows\nREGIZOR: Alberto Corredor\nPRODUCTIE: 2023\n\n");
    m3.addInfo(
            "TITLU ORIGINAL: Baietii buni ajung in Rai 2D\nGENUL FILMULUI:Comedie, Drama\nDISTRIBUTIE: Bogdan Dumitrache, Cosmina Stratan\nREGIZOR: Radu Potcoava\nPRODUCTIE: 2024\n\n");
    m4.addInfo(
            "TITLU ORIGINAL: Kung Fu Panda 4 3D dub 4DX\nGENUL FILMULUI: Aventura, Animatie, Comedie, Familie\nREGIZOR: Mike Mitchell, Stephanie Stine\nPRODUCTIE: 2024\n\n");
    m5.addInfo(
            "TITLU ORIGINAL: Les chambres rouges 2D\nGENUL FILMULUI: Thriller\nDISTRIBUTIE: Juliette Gariapy, Laurie Fortin-Babin, Elisabeth Locas, Maxwell McCabe-Lokos\nREGIZOR: Pascal Plante\nPRODUCTIE: 2023\n\n");
    m6.addInfo(
            "TITLU ORIGINAL: Beautiful wedding 2D\nGENUL FILMULUI: Comedie, Romantic\nDISTRIBUTIE: Virginia Gardner, Dylan Sprouse\nREGIZOR: Roger Kumble\nPRODUCTIE: 2024\n\n");
    m7.addInfo(
            "TITLU ORIGINAL: Dune: Part Two 2D 4DX\nGENUL FILMULUI: Actiune, Aventura, AVANPREMIERA, Drama, Fictiune\nDISTRIBUTIE: Rebecca Ferguson, Timothee Chalamet, Zendaya, Stellan Skarsgard, Javier Bardem\nREGIZOR: Denis Villeneuve\nPRODUCTIE: 2024\n\n");
    m8.addInfo(
            "TITLU ORIGINAL: Io capitan 2D\nGENUL FILMULUI: Drama\nDISTRIBUTIE: Affif Ben Badra, Isaka Sawadogo, Bamar Kane, Hichem Yacoubi, Seydou Sarr\nREGIZOR: Matteo Garrone\nPRODUCTIE: 2023\n\n");
    m9.addInfo(
            "TITLU ORIGINAL: Madame Web 2D 4DX\nGENUL FILMULUI: Actiune, Aventura, Fictiune\nDISTRIBUTIE: Sydney Sweeney, Emma Roberts, Adam Scott, Dakota Johnson, Isabela Merced\nREGIZOR: S.J. Clarkson\nPRODUCTIE: 2024\n\n");
    m10.addInfo(
            "TITLU ORIGINAL: Imaginary 2D\nGENUL FILMULUI: Horror\nDISTRIBUTIE: Betty Buckley, DeWanda Wise, Veronica Falcon, Matthew Sato\nREGIZOR: Jeff Wadlow\nPRODUCTIE: 2024\n\n");
    m11.addInfo(
            "TITLU ORIGINAL: Sleeping dogs 2D\nGENUL FILMULUI: Crima, Mister, Thriller\nDISTRIBUTIE: Karen Gillan, Russell Crowe, Marton Csokas, Tommy Flanagan\nREGIZOR: Adam Cooper\nPRODUCTIE: 2024\n\n");
    m12.addInfo(
            "TITLU ORIGINAL: The iron claw 2D\nGENUL FILMULUI: Biografic, Drama, Sport\nDISTRIBUTIE: Zac Efron, Jeremy Allen White, Harris Dickinson, Maura Tierney, Holt McCallany\nREGIZOR: Sean Durkin\nPRODUCTIE: 2023\n\n");
    m13.addInfo(
            "TITLU ORIGINAL: Immaculate 2D\nGENUL FILMULUI: Horror\nDISTRIBUTIE: Sydney Sweeney\nREGIZOR: Michael Mohan\nPRODUCTIE: 2024\n\n");

    m1.addHour({"12:10", "14:20", "16:40", "18:50"});
    m2.addHour({"22:10", "22:40"});
    m3.addHour({"19:30", "20:30"});
    m12.addHour({"18:00", "22:20"});
    m5.addHour({"14:30", "17:10", "19:50"});
    m6.addHour({"12:00", "15:00", "17:00", "22:30"});
    m7.addHour({"17:00", "19:40"});
    m8.addHour({"15:20", "17:50", "20:20", "22:40"});
    m9.addHour({"18:50", "19:50"});
    m10.addHour({"11:10", "13:45", "16:30"});
    m11.addHour({"17:40", "19:30", "22:20"});
    m13.addHour({"19:45", "21:50"});
    m4.addHour({"14:50", "17:30", "20:00"});

    filme.push_back(m1);
    filme.push_back(m2);
    filme.push_back(m3);
    filme.push_back(m4);
    filme.push_back(m5);
    filme.push_back(m6);
    filme.push_back(m7);
    filme.push_back(m8);
    filme.push_back(m9);
    filme.push_back(m10);
    filme.push_back(m11);
    filme.push_back(m12);
    filme.push_back(m13);

    Cinema s1("sala1");
    s1.addMovies({m10, m11}, {"11:10", "13:45", "16:30", "17:40", "19:30", "22:20"});

    Cinema s2("sala2");
    s2.addMovies({m1, m3, m9}, {"12:10", "14:20", "16:40", "18:50", "19:30", "20:30", "18:50", "19:50"});

    Cinema s3("sala3");
    s3.addMovies({m4, m5}, {"14:50", "17:30", "20:00", "14:30", "17:10", "19:50"});

    Cinema s4("sala4");
    s4.addMovies({m6}, {"12:00", "15:00", "17:00", "22:30"});

    Cinema s5("sala5");
    s5.addMovies({m7, m8}, {"17:00", "19:40", "15:20", "17:50", "20:20", "22:40"});

    Cinema s6("sala6");
    s6.addMovies({m2, m12}, {"22:10", "22:40", "18:00", "22:20"});

    Cinema s7("sala7");
    s7.addMovies({m13}, {"19:45", "21:50"});

    sali.push_back(s1);
    sali.push_back(s2);
    sali.push_back(s3);
    sali.push_back(s4);
    sali.push_back(s5);
    sali.push_back(s6);
    sali.push_back(s7);
}

int viewInfoMovies(Profile &profil, std::vector<Movie>& filmeDisponibile, std::vector<Cinema> &saliDeCinema,
                    std::vector<Day> &zile){
int optIndex;
    std::cout << "1.Faceti rezervare\n" << "2.Vizualizare filme\n" << std::endl << "Alegeti optiunea:";
    std::cin>> optIndex;

    if (optIndex == 2) {
        for (int cnt = 0; cnt < filmeDisponibile.size(); cnt++) {
            std::cout << cnt + 1 << "." << filmeDisponibile[cnt].getName() << std::endl;
        }
        std::cout << "\nDoriti sa aflati informatii despre un anumit film?  <<DA>>  <<NU>> :";
        std::string dasaunu;
        std::cin>> dasaunu;
        std::cout << std::endl;
        if (dasaunu == "DA")
            optIndex = 3;
        else if(dasaunu=="NU"){
            std::cout << "Doriti sa faceti o rezervare?  <<DA>>  <<NU>> :";
            std::cin>> dasaunu;
            std::cout << std::endl;
            if (dasaunu == "DA")
                optIndex = 1;
            else if(dasaunu=="NU") {
                std::cout << "O zi buna!";
                optIndex = -1;
                return 0;
            }
        }
    }
    if (optIndex == 3) {
        optIndex = 2;
        while (optIndex == 2) {
            int cnt;
            std::cout << std::endl << "Alegeti filmul:";
            std::cin>> cnt;
            std::cout << std::endl;
            std::cout << filmeDisponibile[cnt - 1].getInfo();
            std::cout << "\n1.Faceti rezervare\n" << "2.Informatii despre alte filme\n\n" << "Alegeti optiunea:";
            std::cin>> optIndex;
        }

    }

}

int makeReservation(Profile &profil, std::vector<Movie>& filmeDisponibile, std::vector<Cinema> &saliDeCinema,
                    std::vector<Day> &zile, std::vector<Profile> &toateProfilele) {

    int optIndex;
    std::cout << "1.Faceti rezervare\n" << "2.Vizualizare filme\n" << std::endl << "Alegeti optiunea:";
    std::cin>> optIndex;

    if (optIndex == 2) {
        for (int cnt = 0; cnt < filmeDisponibile.size(); cnt++) {
            std::cout << cnt + 1 << "." << filmeDisponibile[cnt].getName() << std::endl;
        }
        std::cout << "\nDoriti sa aflati informatii despre un anumit film?  <<DA>>  <<NU>> :";
        std::string daSauNuFilme;
        std::cin>> daSauNuFilme;
        std::cout << std::endl;
        if (daSauNuFilme == "DA")
            optIndex = 3;
        else if(daSauNuFilme=="NU"){
            std::string daSauNuRezervare;
            std::cout << "Doriti sa faceti o rezervare?  <<DA>>  <<NU>> :";
            std::cin>> daSauNuRezervare;
            std::cout << std::endl;
            if (daSauNuRezervare == "DA")
                optIndex = 1;
            else if(daSauNuRezervare=="NU") {
                return 1;
            }
        }
    }
    if (optIndex == 3) {
        optIndex = 2;
        while (optIndex == 2) {
            int cnt;
            std::cout << std::endl << "Alegeti filmul:";
            std::cin>> cnt;
            std::cout << std::endl;
            std::cout << filmeDisponibile[cnt - 1].getInfo();
            std::cout << "\n1.Faceti rezervare\n" << "2.Informatii despre alte filme\n\n" << "Alegeti optiunea:";
            std::cin>> optIndex;
        }

    }

    if (optIndex == 1) {
        int ziuaIndex;

        std::cout << "\n1.Luni\n";
        std::cout << "2.Marti\n";
        std::cout << "3.Miercuri\n";
        std::cout << "4.Joi\n";
        std::cout << "5.Vineri\n";
        std::cout << "6.Sambata\n";
        std::cout << "7.Duminica\n";

        std::cout << "\nAlegeti ziua:";
        std::cin>> ziuaIndex;
        std::cout << std::endl;

        std::vector<std::string> filme;
        for (const auto &film: zile[ziuaIndex - 1].getMovies()) 
            filme.push_back(film);
        
        for (int i = 0; i < filme.size(); i++) 
            std::cout << i + 1 << "." << filme[i] << std::endl;
        
        int filmIndex;
        std::cout << std::endl;

        std::cout << "Alegeti filmul:";
        std::cin>> filmIndex;
        std::cout << std::endl;
        int auxMovieAvail = zile[ziuaIndex - 1].movieAvailability(filmIndex);
        while (auxMovieAvail == 0) {
            std::cout << "Filmul selectat nu se difuzeaza " << zile[ziuaIndex - 1].getName()
                      << ". Alegeti un alt film:";
            std::cin>> filmIndex;
            auxMovieAvail = zile[ziuaIndex - 1].movieAvailability(filmIndex);
        }

        std::cout << std::endl << "1.Orele valabile" << std::endl << "2.Informatii despre film" << std::endl
                  << "Alegeti optiunea:";
        int optiuneFilm;
        std::cin>> optiuneFilm;
        std::cout << std::endl;
        int ok3;
        //filme[filmIndex-1] filmul ales in string
        int optiuneOreValabile;
        int ind;
        for (int i = 0; i <= filmeDisponibile.size(); i++) 
            if (filmeDisponibile[i].getName() == filme[filmIndex - 1]) {
                ind = i;
                break;
            }
        
        if (optiuneFilm == 2) {
            std::cout << filmeDisponibile[ind].getInfo();
            std::cout << "1.Orele valabile:";
            std::cin>> optiuneOreValabile;
        }
        if (optiuneFilm == 1 || optiuneOreValabile == 1) {
            filmeDisponibile[ind].showHours();
            std::cout << "\n\nAlegeti ora:";
            std::string ora;
            std::cin>> ora;
            ok3 = filmeDisponibile[ind].hourAvailability(ora);
            while (ok3 == 0) {
                std::cout << "\nOra indisponibila. Alegeti o alta ora:";
                std::cin>> ora;
                ok3 = filmeDisponibile[ind].hourAvailability(ora);
            }
            //filmeDisponibile[ind] filmul ales in Movie
            int indSala;    //indexul salii in care se rezerva filmul
            int indFilmOra;
            for (int i = 0; i < saliDeCinema.size(); i++)
                for (int j = 0; j < saliDeCinema[i].getMovies().size(); j++)
                    if (filmeDisponibile[ind].getName() + "-" + ora == saliDeCinema[i].getMovies()[j]) {
                        indSala = i;
                        indFilmOra = j;
                        break;
                    }
                
            std::cout << "Locuri disponibile:"
                      << saliDeCinema[indSala].getAvailableSeats(filmeDisponibile[ind].getName() + "-" + ora)
                      << ". Alegeti numarul de locuri:";
            int nrLocuri;
            std::cin>> nrLocuri;
            //std::cout<<indSala<<std::endl<<indFilmOra;
            while (saliDeCinema[indSala].getAvailableSeats(filmeDisponibile[ind].getName() + "-" + ora) < nrLocuri) {
                std::cout << "Numar indisponibil de locuri pentru rezervare.\n" << "Modificati numarul de locuri:\n";
                std::cin>> nrLocuri;      
            }

            if (saliDeCinema[indSala].getAvailableSeats(filmeDisponibile[ind].getName() + "-" + ora) >= nrLocuri) {
                saliDeCinema[indSala].occupySeats(filmeDisponibile[ind], ora, nrLocuri);
                std::cout << "Locuri disponibile:"
                          << saliDeCinema[indSala].getAvailableSeats(filmeDisponibile[ind].getName() + "-" + ora);
            }
            profil.newReservation(zile[ziuaIndex - 1].getName(), filmeDisponibile[ind].getName(), ora,
                                  saliDeCinema[indSala].getName(), std::to_string(nrLocuri));


            std::cout << ". Rezervare finalizata!\nDoriti sa vedeti rezervarea? <<DA>>  <<NU>> :";
            std::string dasaunuRezervare;
            std::cin>>dasaunuRezervare;
            if (dasaunuRezervare == "DA") {
                std::cout << std::endl;
                std::cout << profil;
                std::cout << "\n1.Faceti o noua rezervare\n2.Inapoi la inceput\nAlegeti optiunea:";
                int al10leaindex;
                std::cin>> al10leaindex;
                if (al10leaindex == 1)
                    makeReservation(profil, filmeDisponibile, saliDeCinema, zile, toateProfilele);
                return 1;   
            }
            else{
                int al10leaindex=1;
                if (al10leaindex == 1)
                    makeReservation(profil, filmeDisponibile, saliDeCinema, zile, toateProfilele);
                return 1; 
            }     
        }
    }
}

void start(std::vector<Movie> &filmeDisponibile, std::vector<Cinema> &saliDeCinema, std::vector<Day> &zile,
           std::vector<Profile> &toateProfilele) {

    std::cout << "1.Creati un profil\n2.Conectati-va la un profil deja existent\n3.Sfarsitul rezervarii\nAlegeti optiunea:";
    int index;
    std::cin>> index;
    std::string nume;
    std::string parola;

    if (index == 2) {
        if (toateProfilele.size() == 0) {
            std::cout << "Profil inexistent.\n";
            index = 1;
        }
        else {
            std::cout << "Nume:";
            std::cin>> nume;
            std::cout << "Parola:";
            std::cin>> parola;
            for (auto i: toateProfilele) {
                int ok = i.checkProfile(nume, parola);
                while (ok == 0) {
                    std::cout << "Parola incorecta.\nParola:";
                    std::cin>> parola;
                    ok = i.checkProfile(nume, parola);
                }
                if (ok == 1) {
                    int ok1 = makeReservation(i, filmeDisponibile, saliDeCinema, zile, toateProfilele);

                    if(!ok1) return;

                    if (ok1 == 1)
                        start(filmeDisponibile, saliDeCinema, zile, toateProfilele);
                }
                else if (ok == -1) {
                    std::cout << "Profil inexistent.\n";
                    index = 1;
                }
            }
        }
    }
    if (index == 1) {
        std::cout << "Adaugati numele profilului:";
        std::cin>> nume;
        std::cout << "Adaugati o parola:";
        std::cin>> parola;
        Profile p(nume, parola);
        std::cout << "Profilul a fost creat.\n";
        toateProfilele.push_back(p);
        if (makeReservation(p, filmeDisponibile, saliDeCinema, zile, toateProfilele) == 1)
            start(filmeDisponibile, saliDeCinema, zile, toateProfilele);
    }
    if(index==3)
        std::cout<<"O zi buna!";
}

int main() {
    
    std::vector<Movie> filmeDisponibile;
    std::vector<Cinema> saliDeCinema;
    std::vector<Day> zile;
    std::vector<Profile> profile = {};
    setMovies(filmeDisponibile, saliDeCinema);
    setDays(zile);
    start(filmeDisponibile, saliDeCinema, zile, profile);

    return 0;
}