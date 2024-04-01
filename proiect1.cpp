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

    void addMovie(const std::vector<std::string> movieNames){
        for(auto i:movieNames)
            movies.push_back(i);
    }

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

    int checkHour(std::string hour){
        for(auto i:hours)
            if(hour==i)
                return 1;
        return 0;
    }
public:
    Movie(const std::string name):name{name}{hours={};description="";}
    
    void addHour(std::vector<std::string> ore){
        for(auto i:ore)
            hours.push_back(i);
    }

    void showHours(){
        std::cout<<"|";
        for(const auto& hour:hours){
            std::cout<<hour<<"|";
        }
    }

    std::vector<std::string> getHours() const{return hours;}

    const std::string getName() const{return name;}

    void addInfo(const std::string description){this->description=description;}

    std::string getInfo() const{return description;}

    int hourAvailability(std::string oraAleasa){
        for(int i=0;i<=hours.size();i++){
            if(oraAleasa==hours[i]){
                return 1;
            }
        }
        return 0;
    }

    friend class Cinema;
};

class Cinema{
private:
    const std::string name;
    std::vector<std::string> movies;
    std::vector<int> seats={40};

public:
    Cinema(const std::string name):name{name}{}

    void addMovies(std::vector<Movie> m,std::vector<std::string> h){
        for(int i=0;i<m.size();i++)
            for(int j=0;j<h.size();j++)
                if(m[i].checkHour(h[j])==1){
                    movies.push_back(m[i].getName()+"-"+h[j]);
                    seats.push_back(40);
                }
    }
    int occupySeats(Movie movie,std::string hour,int number_of_seats){
        int counter=-1;
        for(int cnt=0;cnt<movies.size();cnt++){
            if(movies[cnt]==movie.getName()+"-"+hour){
                if(seats[cnt]>=number_of_seats){
                    seats[cnt]-=number_of_seats;
                    counter=cnt;
                    break;
                    }
            }
        }
        if(counter<0){
            return 0;
        }
        else return 1;
    }
    std::string getName() const{return name;}

    std::vector<std::string> getMovies() const{return movies;}

    friend std::ostream& operator<<(std::ostream& os,const Cinema& salacinema);
};

std::ostream& operator<<(std::ostream& os,const Cinema& salacinema){
    int cnt=0;
    os<<salacinema.getName()<<":"<<std::endl;
    for(auto i:salacinema.getMovies()){
        os<<i<<"||";
    }
    return os;
}

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

    Luni.addMovie({ "2020", "Baghead:Mesagerul Mortii", "Baietii buni ajung in rai", "Kung Fu Panda 4", "Camera Rosie", "Casatoriti din greseala", "Dune:Partea II", "Eu capitan" });
    Marti.addMovie({ "2020", "Baghead:Mesagerul Mortii", "Baietii buni ajung in rai", "Kung Fu Panda 4", "Camera Rosie", "Casatoriti din greseala", "Dune:Partea II", "Eu capitan", "Madame Web", "Demonul copilariei" });
    Miercuri.addMovie({ "Baghead:Mesagerul Mortii", "Baietii buni ajung in rai", "Kung Fu Panda 4", "Camera Rosie", "Casatoriti din greseala", "Dune:Partea II", "Eu capitan", "Madame Web", "Demonul copilariei" });
    Joi.addMovie({ "Baghead:Mesagerul Mortii", "Baietii buni ajung in rai", "Kung Fu Panda 4", "Camera Rosie", "Casatoriti din greseala", "Dune:Partea II", "Eu capitan", "Madame Web", "Demonul copilariei" });
    Vineri.addMovie({ "Kung Fu Panda 4", "Camera Rosie", "Casatoriti din greseala", "Dune:Partea II", "Eu capitan", "Madame Web", "Demonul copilariei", "Fantomele trecutului", "Gheara de fier", "Imaculata" });
    Sambata.addMovie({ "Kung Fu Panda 4", "Camera Rosie", "Casatoriti din greseala", "Dune:Partea II", "Eu capitan", "Madame Web", "Demonul copilariei", "Fantomele trecutului", "Gheara de fier", "Imaculata" });
    Duminica.addMovie({ "Kung Fu Panda 4", "Camera Rosie", "Casatoriti din greseala", "Dune:Partea II", "Eu capitan", "Madame Web", "Demonul copilariei", "Fantomele trecutului", "Gheara de fier", "Imaculata" });

    zile.push_back(Luni);
    zile.push_back(Marti);
    zile.push_back(Miercuri);
    zile.push_back(Joi);
    zile.push_back(Vineri);
    zile.push_back(Sambata);
    zile.push_back(Duminica);
  
}

void setMovies(std::vector<Movie>& filme,std::vector<Cinema>& sali){

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

    m1.addHour({ "12:10", "14:20", "16:40", "18:50" });
    m2.addHour({ "22:10", "22:40" });
    m3.addHour({ "19:30", "20:30" });
    m12.addHour({ "18:00", "22:20" });
    m5.addHour({ "14:30", "17:10", "19:50" });
    m6.addHour({ "12:00", "15:00", "17:00", "22:30" });
    m7.addHour({ "17:00", "19:40" });
    m8.addHour({ "15:20", "17:50", "20:20", "22:40" });
    m9.addHour({ "18:50", "19:50" });
    m10.addHour({ "11:10", "13:45", "16:30" });
    m11.addHour({ "17:40", "19:30", "22:20" });
    m13.addHour({ "19:45", "21:50" });
    m4.addHour({ "14:50", "17:30", "20:00" });

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

void makeReservation(Profile profil){
std::cout<<"Filmele difuzate in aceasta saptamana sunt:\n";
    std::vector<Movie> filmeDisponibile;
    std::vector<Cinema> salidecinema;
    setMovies(filmeDisponibile,salidecinema);
    for(auto i:salidecinema)
        std::cout<<i<<std::endl;
    for(const auto film:filmeDisponibile){
        std::cout<<"-"<<film.getName()<<std::endl;
    }
    std::cout<<std::endl;
    
    int optIndex;
    std::cout<<"1.Faceti rezervare"<<std::endl<<"2.Informatii despre filme\n"<<std::endl<<"Alegeti optiunea:";
    std::cin>>optIndex;

while(optIndex==2){
    int cnt;
    for(cnt=0;cnt<=filmeDisponibile.size();cnt++){
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
        for(int i=0;i<=filmeDisponibile.size();i++){
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
        //filmeDisponibile[ind] filmul ales in Movie
        int indsala;    //indexul salii in care se rezerva filmul
        int indfilm_ora;
        for(int i=0;i<salidecinema.size();i++){
            for(int j=0;j<salidecinema[i].getMovies().size();j++){
                if(filmeDisponibile[ind].getName()+"-"+ora==salidecinema[i].getMovies()[j]){
                    indsala=i;
                    indfilm_ora=j;
                    break; 
                } 
            }
                            
        }
        //std::cout<<indsala<<std::endl<<indfilm_ora;
        while(salidecinema[indsala].occupySeats(filmeDisponibile[ind],ora,nrLocuri)==0){
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

        std::cout<<"Rezervare finalizata!\n1.Afisati rezervarea\n2.Faceti o noua rezervare\n3.Schimbati profilul\n";
        int al10leaindex;
        std::cout<<"Alegeti optiunea:";
        std::cin>>al10leaindex;
        std::cout<<std::endl;
        if(al10leaindex==1){
            std::cout<<"Ziua: "<<zile[ziuaIndex-1].getName()<<std::endl;
            std::cout<<"Filmul: "<<filmeDisponibile[ind].getName()<<std::endl;
            std::cout<<"Ora: "<<ora<<std::endl;
            std::cout<<"Sala: "<<salidecinema[indsala].getName()<<std::endl;
            std::cout<<"Numar de locuri: "<<nrLocuri<<std::endl;
        }
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