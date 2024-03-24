#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

class Day{
private:
    const std::string name;
    std::list <std::string> movies;
public:
    Day(const std::string name):name{name}{movies={};}

    void addMovie(const std::string movieName){movies.push_back(movieName);}

    const std::list <std::string> getMovies(){return movies;}

    const std::string getName() const {return name;}
    
    int movieAvailability(int filmIndex){
        if(filmIndex>std::distance(movies.begin(),movies.end())){
            return 0;
        }
        else{
            return 1;
        }
    }
};

class Movie{
private:
    const std::string name;
    std::vector <std::string> hours;
    std::string description;
    int seats=40;
public:
    Movie(const std::string name):name{name}{hours={};description="";}
    
    void addHour(std::string ora){hours.push_back(ora);}

    void showHours(){
        std::cout<<"|";
        for(const auto& hour:hours){
            std::cout<<hour<<"|";
        }
    }

    const std::string getName() const{return name;}

    int occupySeats(int nrlocuri){
        if(seats<nrlocuri){
            return 0;
        }
        else{
            seats-=nrlocuri;
        }
    }

    //int getSeats() const{return seats;}

    void addInfo(const std::string description){this->description=description;}

    std::string getInfo() const{return description;}

    int hourAvailability(std::string oraAleasa){
        for(int i=0;i<=sizeof(hours);i++){
            if(oraAleasa==hours[i]){
                return 1;
            }
        }
        return 0;
    }

};

class Profile{
private:
    const std::string name;
    std::vector<std::string> reservations;
public:
    Profile(const std::string name):name{name}{reservations={};}

    void newReservation(Movie film,std::string ora){
        std::string aux=film.getName()+"-"+ora;

        reservations.push_back(aux);
    }
    const std::string getName() const {return name;}

    friend std::ostream& operator<<(std::ostream& os,const Profile& profile);
};

std::ostream& operator<<(std::ostream& os,const Profile& profile){
    int cnt=0;
    os<<"Afisam rezervarile profilului cu numele "<<profile.getName()<<":"<<std::endl;
    for(auto it=profile.reservations.begin();it!=profile.reservations.end();it++){
        std::string det=*it;
        os<<det;
    }
    return os;
}

void setDays(std::vector<Day>& zile){

    Day Luni("luni");
    Day Marti("marti");
    Day Miercuri("miercuri");
    Day Joi("joi");
    Day Vineri("vineri");
    Day Sambata("sambata");
    Day Duminica("duminica");

    Luni.addMovie("2020");
    Luni.addMovie("Baghead:Mesagerul Mortii");
    Luni.addMovie("Baietii buni ajung in rai");
    Luni.addMovie("Kung Fu Panda 4");
    Luni.addMovie("Camera Rosie");
    Luni.addMovie("Casatoriti din greseala");
    Luni.addMovie("Dune:Partea II");
    Luni.addMovie("Eu capitan");

    Marti.addMovie("2020");
    Marti.addMovie("Baghead:Mesagerul Mortii");
    Marti.addMovie("Baietii buni ajung in rai");
    Marti.addMovie("Kung Fu Panda 4");
    Marti.addMovie("Camera Rosie");
    Marti.addMovie("Casatoriti din greseala");
    Marti.addMovie("Dune:Partea II");
    Marti.addMovie("Eu capitan");
    Marti.addMovie("Madame Web");
    Marti.addMovie("Demonul copilariei");

    Miercuri.addMovie("Baghead:Mesagerul Mortii");
    Miercuri.addMovie("Baietii buni ajung in rai");
    Miercuri.addMovie("Kung Fu Panda 4");
    Miercuri.addMovie("Camera Rosie");
    Miercuri.addMovie("Casatoriti din greseala");
    Miercuri.addMovie("Dune:Partea II");
    Miercuri.addMovie("Eu capitan");
    Miercuri.addMovie("Madame Web");
    Miercuri.addMovie("Demonul copilariei");

    Joi.addMovie("Baghead:Mesagerul Mortii");
    Joi.addMovie("Baietii buni ajung in rai");
    Joi.addMovie("Kung Fu Panda 4");
    Joi.addMovie("Camera Rosie");
    Joi.addMovie("Casatoriti din greseala");
    Joi.addMovie("Dune:Partea II");
    Joi.addMovie("Eu capitan");
    Joi.addMovie("Madame Web");
    Joi.addMovie("Demonul copilariei");

    Vineri.addMovie("Kung Fu Panda 4");
    Vineri.addMovie("Camera Rosie");
    Vineri.addMovie("Casatoriti din greseala");
    Vineri.addMovie("Dune:Partea II");
    Vineri.addMovie("Eu capitan");
    Vineri.addMovie("Madame Web");
    Vineri.addMovie("Demonul copilariei");
    Vineri.addMovie("Fantomele trecutului");
    Vineri.addMovie("Gheara de fier");
    Vineri.addMovie("Imaculata");

    Sambata.addMovie("Kung Fu Panda 4");
    Sambata.addMovie("Camera Rosie");
    Sambata.addMovie("Casatoriti din greseala");
    Sambata.addMovie("Dune:Partea II");
    Sambata.addMovie("Eu capitan");
    Sambata.addMovie("Madame Web");
    Sambata.addMovie("Demonul copilariei");
    Sambata.addMovie("Fantomele trecutului");
    Sambata.addMovie("Gheara de fier");
    Sambata.addMovie("Imaculata");

    Duminica.addMovie("Kung Fu Panda 4");
    Duminica.addMovie("Camera Rosie");
    Duminica.addMovie("Casatoriti din greseala");
    Duminica.addMovie("Dune:Partea II");
    Duminica.addMovie("Eu capitan");
    Duminica.addMovie("Madame Web");
    Duminica.addMovie("Demonul copilariei");
    Duminica.addMovie("Fantomele trecutului");
    Duminica.addMovie("Gheara de fier");
    Duminica.addMovie("Imaculata");

    zile.push_back(Luni);
    zile.push_back(Marti);
    zile.push_back(Miercuri);
    zile.push_back(Joi);
    zile.push_back(Vineri);
    zile.push_back(Sambata);
    zile.push_back(Duminica);
  
}

void setMovies(std::vector<Movie>& filme){

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

    m1.addInfo("TITLU ORIGINAL: 2020 2D\nGENUL FILMULUI: Comedie, Drama\nDISTRIBUTIE: Silviu Geamanu, Puiu Mircea Lascus, Simona Maicanescu\nREGIZOR: Bobby Barbacioru\nPRODUCTIE: 2023\n\n");
    m2.addInfo("TITLU ORIGINAL: Baghead 2D\nGENUL FILMULUI: Horror\nDISTRIBUTIE: Freya Allan, Peter Mullan, Saffron Burrows\nREGIZOR: Alberto Corredor\nPRODUCTIE: 2023\n\n");
    m3.addInfo("TITLU ORIGINAL: Baietii buni ajung in Rai 2D\nGENUL FILMULUI:Comedie, Drama\nDISTRIBUTIE: Bogdan Dumitrache, Cosmina Stratan\nREGIZOR: Radu Potcoava\nPRODUCTIE: 2024\n\n");
    m4.addInfo("TITLU ORIGINAL: Kung Fu Panda 4 3D dub 4DX\nGENUL FILMULUI: Aventura, Animatie, Comedie, Familie\nREGIZOR: Mike Mitchell, Stephanie Stine\nPRODUCTIE: 2024\n\n");
    m5.addInfo("TITLU ORIGINAL: Les chambres rouges 2D\nGENUL FILMULUI: Thriller\nDISTRIBUTIE: Juliette Gariapy, Laurie Fortin-Babin, Elisabeth Locas, Maxwell McCabe-Lokos\nREGIZOR: Pascal Plante\nPRODUCTIE: 2023\n\n");
    m6.addInfo("TITLU ORIGINAL: Beautiful wedding 2D\nGENUL FILMULUI: Comedie, Romantic\nDISTRIBUTIE: Virginia Gardner, Dylan Sprouse\nREGIZOR: Roger Kumble\nPRODUCTIE: 2024\n\n");
    m7.addInfo("TITLU ORIGINAL: Dune: Part Two 2D 4DX\nGENUL FILMULUI: Actiune, Aventura, AVANPREMIERA, Drama, Fictiune\nDISTRIBUTIE: Rebecca Ferguson, Timothee Chalamet, Zendaya, Stellan Skarsgard, Javier Bardem\nREGIZOR: Denis Villeneuve\nPRODUCTIE: 2024\n\n");
    m8.addInfo("TITLU ORIGINAL: Io capitan 2D\nGENUL FILMULUI: Drama\nDISTRIBUTIE: Affif Ben Badra, Isaka Sawadogo, Bamar Kane, Hichem Yacoubi, Seydou Sarr\nREGIZOR: Matteo Garrone\nPRODUCTIE: 2023\n\n");
    m9.addInfo("TITLU ORIGINAL: Madame Web 2D 4DX\nGENUL FILMULUI: Actiune, Aventura, Fictiune\nDISTRIBUTIE: Sydney Sweeney, Emma Roberts, Adam Scott, Dakota Johnson, Isabela Merced\nREGIZOR: S.J. Clarkson\nPRODUCTIE: 2024\n\n");
    m10.addInfo("TITLU ORIGINAL: Imaginary 2D\nGENUL FILMULUI: Horror\nDISTRIBUTIE: Betty Buckley, DeWanda Wise, Veronica Falcon, Matthew Sato\nREGIZOR: Jeff Wadlow\nPRODUCTIE: 2024\n\n");
    m11.addInfo("TITLU ORIGINAL: Sleeping dogs 2D\nGENUL FILMULUI: Crima, Mister, Thriller\nDISTRIBUTIE: Karen Gillan, Russell Crowe, Marton Csokas, Tommy Flanagan\nREGIZOR: Adam Cooper\nPRODUCTIE: 2024\n\n");
    m12.addInfo("TITLU ORIGINAL: The iron claw 2D\nGENUL FILMULUI: Biografic, Drama, Sport\nDISTRIBUTIE: Zac Efron, Jeremy Allen White, Harris Dickinson, Maura Tierney, Holt McCallany\nREGIZOR: Sean Durkin\nPRODUCTIE: 2023\n\n");
    m13.addInfo("TITLU ORIGINAL: Immaculate 2D\nGENUL FILMULUI: Horror\nDISTRIBUTIE: Sydney Sweeney\nREGIZOR: Michael Mohan\nPRODUCTIE: 2024\n\n");


    m1.addHour("12:10");
    m1.addHour("14:20");
    m1.addHour("16:40");
    m1.addHour("18:50");
    m2.addHour("22:10");
    m2.addHour("22:40");
    m3.addHour("19:30");
    m3.addHour("20:30");
    m12.addHour("18:00");
    m12.addHour("22:20");
    m5.addHour("14:30");
    m5.addHour("17:10");
    m5.addHour("19:50");
    m6.addHour("12:00");
    m6.addHour("15:00");
    m6.addHour("17:00");
    m6.addHour("22:30");
    m7.addHour("17:00");
    m7.addHour("19:40");
    m8.addHour("15:20");
    m8.addHour("17:50");
    m8.addHour("20:20");
    m8.addHour("22:40");
    m9.addHour("18:50");
    m9.addHour("19:50");
    m10.addHour("11:10");
    m10.addHour("13:45");
    m10.addHour("16:30");
    m11.addHour("17:40");
    m11.addHour("19:30");
    m11.addHour("22:20");
    m13.addHour("19:45");
    m13.addHour("21:50");
    m4.addHour("14:50");
    m4.addHour("17:30");
    m4.addHour("20:00");

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

}

void makeReservation(Profile profil){
std::cout<<"Filmele difuzate in aceasta saptamana sunt:\n";
    std::vector<Movie> filmeDisponibile;
    setMovies(filmeDisponibile);
    for(const auto film:filmeDisponibile){
        std::cout<<"-"<<film.getName()<<std::endl;
    }
    std::cout<<std::endl;
    
    int optIndex;
    std::cout<<"1.Faceti rezervare"<<std::endl<<"2.Informatii despre filme\n"<<std::endl<<"Alegeti optiunea:";
    std::cin>>optIndex;

while(optIndex==2){
    int cnt;
    for(cnt=0;cnt<=sizeof(filmeDisponibile);cnt++){
        std::cout<<cnt+1<<"."<<filmeDisponibile[cnt].getName()<<std::endl;
    }
    std::cout<<std::endl<<"Alegeti filmul:";
    std::cin>>cnt;
    std::cout<<std::endl;
    std::cout<<filmeDisponibile[cnt-1].getInfo();
    std::cout<<"1.Faceti rezervare\n"<<"2.Informatii despre alte filme\n\n"<<"Alegeti optiunea:";
    std::cin>>optIndex;
}

if(optIndex==1){
    std::vector<Day> zile;
    setDays(zile);

    int ziuaIndex;

    std::cout<<"\n1.Luni\n";
    std::cout<<"2.Marti\n";
    std::cout<<"3.Miercuri\n";
    std::cout<<"4.Joi\n";
    std::cout<<"5.Vineri\n";
    std::cout<<"6.Sambata\n";
    std::cout<<"7.Duminica\n";
    
    std::cout<<"\nAlegeti ziua:";
    std::cin>>ziuaIndex;
    std::cout<<std::endl;
    
    std::vector<std::string> filme;
    for(const auto& film:zile[ziuaIndex-1].getMovies()){
        filme.push_back(film);
    }
    for(int i=0;i<filme.size();i++){
        std::cout<<i+1<<"."<<filme[i]<<std::endl;
    }
    int filmIndex;
    std::cout<<std::endl;
    
    std::cout<<"Alegeti filmul:";
    std::cin>>filmIndex;
    std::cout<<std::endl;
    int ok=zile[ziuaIndex-1].movieAvailability(filmIndex);
    while(ok==0){
        std::cout<<"Filmul selectat nu se difuzeaza "<<zile[ziuaIndex-1].getName()<<". Alegeti un alt film:";
        std::cin>>filmIndex;
        ok=zile[ziuaIndex-1].movieAvailability(filmIndex);
    }

    std::cout<<std::endl<<"1.Orele valabile"<<std::endl<<"2.Informatii despre film"<<std::endl<<"Alegeti optiunea:";
    int aux;
    std::cin>>aux;
    std::cout<<std::endl;
    //filme[filmIndex-1] filmul ales in string
    int k;int ind;
        for(int i=0;i<=sizeof(filmeDisponibile);i++){
        if(filmeDisponibile[i].getName()==filme[filmIndex-1]){
            ind=i;
            break;
        }
        }
    if(aux==2){   
        std::cout<<filmeDisponibile[ind].getInfo();
        std::cout<<"1.Orele valabile:";
        std::cin>>k;
    }
    if(aux==1||k==1){
        filmeDisponibile[ind].showHours();
        std::cout<<"\n\nAlegeti ora:";
        std::string ora;
        std::cin>>ora;
        ok=filmeDisponibile[ind].hourAvailability(ora);
        while(ok==0){
            std::cout<<"\nOra indisponibila. Alegeti o alta ora:";
            std::cin>>ora;
            ok=filmeDisponibile[ind].hourAvailability(ora);
        }
        std::cout<<"\nAlegeti numarul de locuri:";
        int nrLocuri;
        std::cin>>nrLocuri;
        while(filmeDisponibile[ind].occupySeats(nrLocuri)==0){
            std::cout<<"Numar indisponibil de locuri pentru rezervare.\n"<<"1.Modificati numarul de locuri\n"<<"2.Alegeti un alt film\n";
            std::cout<<"Alegeti optiunea:";
            int altindex;
            std::cin>>altindex;
            if(altindex==1){
                std::cout<<"\nAlegeti numarul de locuri:";
                std::cin>>nrLocuri;
            }
            else{
                makeReservation(profil);
            }
        }
        profil.newReservation(filmeDisponibile[ind],ora);

        std::cout<<"Rezervare finalizata!";
        
    }
}
}

int main(){
    std::cout<<"Adaugati numele profilului:";
    std::string nume;
    std::cin>>nume;
    Profile p(nume);
    makeReservation(nume);
    
    return 0;
}