#include<stdio.h>
#include<math.h>
#define PHI 3.14 //cons

//buat tipe data abstrak string dari tipe data char
typedef char* String;

//deklarasi variabel
int i, pil;
char pilihan;
float v, l, r, t, s,
      luas_alas,
      jumlah_luas_stegak,
      a_segitiga,
      t_segitiga,
      t_prisma,
      kll_a_segitiga;

//deklarasi prosedur
void garis(int n);
void judul();
void menu();

//deklarasi fungsi
float volume_tabung(float r, float t);
float luas_tabung(float r, float t);
float volume_bola(float r);
float luas_bola(float r);
float volume_limas(float luas_alas, float t);
float luas_limas(float luas_alas, float jumlah_luas_stegak);
float luas_segitiga(float a_segitiga, float t_segitiga);
float volume_prisma(float a_segitiga, float t_segitiga, float t_prisma);
float luas_prisma(float kll_a_segitiga, float t_prisma, float a_segitiga, float t_segitiga);
float s_kerucut(float r, float t);
float volume_kerucut(float r, float t);
float luas_kerucut(float r, float t, float s);
float isAngka(String keterangan);
float isValid(String keterangan);

//fungsi main
int main(){
    judul(); //panggil judul
    menu(); //panggil menu
}

//prosedur menampilkan garis
void garis(int n){
    for(i=0;i<=n;i++){
        printf("=");
    }
}

//fungsi volume tabung
float volume_tabung(float r, float t){
    float v;
    v = PHI*r*r*t;
    return v;
}

//fungsi luas permukaan tabung
float luas_tabung(float r, float t){
    float l;
    l =  2*PHI*r*(r+t);
    return l;
}

//fungsi volume bola
float volume_bola(float r){
    float v;
    v = (1.33333)*PHI*(r*r*r);
    return v;
}

//fungsi luas permukaan bola
float luas_bola(float r){
    float l;
    l = 4*PHI*r*r;
    return l;
}

//fungsi volume limas
float volume_limas(float luas_alas, float t){
    float v;
    v = (0.33333333)*luas_alas*t;
    return v;
}

//fungsi luas permukaan limas
float luas_limas(float luas_alas, float jumlah_luas_stegak){
    float l;
    l = luas_alas + jumlah_luas_stegak;
    return l;
}

//fungsi mencari luas segitiga pada alas prisma
float luas_segitiga(float a_segitiga, float t_segitiga){
    float luas_segitiga;
    luas_segitiga = 0.5*a_segitiga*t_segitiga;
    return luas_segitiga;
}

//fungsi volume prisma
float volume_prisma(float a_segitiga, float t_segitiga, float t_prisma){
    float v;
    v = luas_segitiga(a_segitiga, t_segitiga)*t_prisma;
    return v;
}

//fungsi luas permukaan prisma
float luas_prisma(float kll_a_segitiga, float t_prisma, float a_segitiga, float t_segitiga){
    float l;
    l = (kll_a_segitiga*t_prisma)+(2*luas_segitiga(a_segitiga, t_segitiga));
    return l;
}

//fungsi mencari selimut
float s_kerucut(float r, float t){
    float s;
    s = sqrt((r*r)+(t*t));
    return s;
}

//fungsi volume kerucut
float volume_kerucut(float r, float t){
    float v;
    v = (0.33333333)*PHI*r*r*t;
    return v;
}

//fungsi luas permukaan kerucut
float luas_kerucut(float r, float t, float s){
    float l;
    l = PHI*r*(r+s_kerucut(r,t));
    return l;
}

//fungsi validasi angka
float isAngka(String keterangan){
    float x;
    printf("Masukkan %s : ", keterangan);
    if(scanf("%f", &x) == 0){
        printf("Inputan harus angka, coba lagi!\n\n");
        fflush(stdin); //bersihkan output buffer
        return;
    }
    fflush(stdin);
    return x;
}

//fungsi validasi angka
float isValid(String keterangan){
    float x;
    printf("Masukkan %s : ", keterangan);
    if(scanf("%f", &x) == 0){
        fflush(stdin); //bersihkan output buffer
        return;
    }
    fflush(stdin);
    return x;
}

//prosedur print judul
void judul(){
    garis(32); //panggil prosedur garis
    printf("\nHITUNG VOLUME DAN LUAS PERMUKAAN\n");
    garis(32); //panggil prosedur garis
}

//menu
void menu(){
	printf("\nPilih Menu : ");
	printf("\n[1] Tabung");
	printf("\n[2] Bola");
	printf("\n[3] Limas Segiempat");
	printf("\n[4] Prisma Segitiga");
	printf("\n[5] Kerucut\n\n");

	pil = isValid("Pilihan (1-5)");
    if(isnan(pil))menu();

	switch (pil){
		case 1 :
		    printf("\n[TABUNG]\n");

            jari:
		    r = isAngka("jari jari");
            if(isnan(r))goto jari;

            tinggi:
		    t = isAngka("tinggi ");
            if(isnan(t))goto tinggi;

            v = volume_tabung(r, t);
            l = luas_tabung(r, t);

            printf("\nVolume = 3.14 x r x r x t");
            printf("\n       = 3.14 x %.2f x %.2f x %.2f", r, r, t);
            printf("\n       = %.2f", v);

            printf("\n\nLuas   = 2 x 3.14 x r x (r + t)");
            printf("\n       = 2 x 3.14 x %.2f x (%.2f + %.2f)", r, r, t);
            printf("\n       = 2 x 3.14 x %.2f x %.2f", r, r+t);
            printf("\n       = %.2f", l);

            break;

        case 2 :
            printf("\n[BOLA]\n");

            jari_bola:
		    r = isAngka("jari jari");
            if(isnan(r))goto jari_bola;

            v = volume_bola(r);
            l = luas_bola(r);

            printf("\nVolume = 3/4 x 3.14 x (r x r x r);");
            printf("\n       = 3/4 x 3.14 x (%.2f x %.2f x %.2f)", r, r, r);
            printf("\n       = 3/4 x 3.14 x %.2f", r*r*r);
            printf("\n       = %.2f", v);

            printf("\n\nLuas   = 4 x 3.14 x r x r");
            printf("\n       = 4 x 3.14 x %.2f x %.2f", r, r);
            printf("\n       = %.2f", l);
            break;

        case 3 :
            printf("\n[LIMAS SEGIEMPAT]\n");

            luas_alas:
		    luas_alas = isAngka("luas alas");
            if(isnan(luas_alas))goto luas_alas;

            t_limas:
            t = isAngka("tinggi limas");
            if(isnan(t))goto t_limas;

            sisi_tegak:
            jumlah_luas_stegak = isAngka("jumlah luas 4 sisi tegak");
            if(isnan(jumlah_luas_stegak))goto sisi_tegak;

            v = volume_limas(luas_alas, t);
            l = luas_limas(luas_alas, jumlah_luas_stegak);

            printf("\nVolume = 1/3 x luas alas x t");
            printf("\n       = 1/3 x %.2f x %.2f", luas_alas, t);
            printf("\n       = %.2f", v);

            printf("\n\nLuas   = luas alas + jumlah luas sisi tegak");
            printf("\n       = %.2f + %.2f", luas_alas, jumlah_luas_stegak);
            printf("\n       = %.2f", l);
            break;

        case 4 :
            printf("\n[PRISMA SEGITIGA]\n");

            a_segitiga:
            a_segitiga = isAngka("alas segitiga");
            if(isnan(a_segitiga))goto a_segitiga;

            t_segitiga:
            t_segitiga = isAngka("tinggi segitiga");
            if(isnan(t_segitiga))goto t_segitiga;

            t_prisma:
            t_prisma = isAngka("tinggi prisma");
            if(isnan(t_prisma))goto t_prisma;

            kll_segitiga:
            kll_a_segitiga = isAngka("keliling alas segitiga");
            if(isnan(kll_a_segitiga))goto kll_segitiga;

            v = volume_prisma(a_segitiga, t_segitiga, t_prisma);
            l = luas_prisma(a_segitiga, t_segitiga, kll_a_segitiga, t_prisma);

            printf("\nVolume = (1/2 x a segitiga x t segitiga) x t prisma");
            printf("\n       = (1/2 x %.2f x %.2f) x %.2f", a_segitiga, t_segitiga, t_prisma);
            printf("\n       = %.2f x %.2f", luas_segitiga(a_segitiga, t_segitiga), t_prisma);
            printf("\n       = %.2f", v);

            printf("\n\nLuas   = (kll segitga x t prisma) + 2 x (1/2 x a segitiga x t segitiga)");
            printf("\n       = (%.2f x %.2f) + 2 x (1/2 x %.2f x %.2f)", kll_a_segitiga, t_prisma, a_segitiga, t_segitiga);
            printf("\n       = (%.2f) + 2 x (%.2f)", kll_a_segitiga*t_prisma, luas_segitiga(a_segitiga, t_segitiga));
            printf("\n       = %.2f + %.2f", kll_a_segitiga*t_prisma, 2*luas_segitiga(a_segitiga, t_segitiga));
            printf("\n       = %.2f", l);
            break;

        case 5 :
            printf("\n[KERUCUT]");

            jari_kerucut:
		    r = isAngka("jari jari");
            if(isnan(r))goto jari_kerucut;

            tinggi_kerucut:
		    t = isAngka("tinggi ");
            if(isnan(t))goto tinggi_kerucut;

            v = volume_kerucut(r, t);
            l = luas_kerucut(r, t, s);

            printf("\nVolume = 1/3 x 3.14 x r x r x t");
            printf("\n       = 1/3 x 3.14 x %.2f x %.2f x %.2f", r, r, t);
            printf("\n       = %.2f", v);

            printf("\n\nLuas   = 3.14 x r x (r + s)");
            printf("\n       = 3.14 + %.2f x (%.2f + %.2f)", r, r, s_kerucut(r, t));
            printf("\n       = 3.14 + %.2f x %.2f", r, r+s_kerucut(r, t));
            printf("\n       = %.2f", l);
            break;

        default :
            printf("Inputan harus angka antara 1-5, coba lagi!\n");
            menu();
            break;
	}

    printf("\n\nIngin melakukan lagi? (y/t) : ");
    scanf("%s", &pilihan);

    if ((pilihan == 'y') || (pilihan == 'Y')){ //jika pilihan y, maka lakukan lagi
        menu(); //rekursif
    }
}

