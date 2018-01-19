#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void tri_bulle(int *tab, int taille) {
	int  tmp;
  	 for (int i = 0; i < taille-1; i++)      
       for (int j = 0; j < taille-i-1; j++) 
           if (tab[j] > tab[j+1])
              {
              	tmp = tab[j];
              	tab[j] = tab[j+1];
              	tab[j+1] = tmp;
              }
}

void tri_selection(int *tab, int taille){
	int i, imin, j, tmp;
	for(i=0; i<taille; i++){
		imin=i;
		for(j=i+1; j<taille; j++){
			if(tab[j]<tab[imin]){
				imin=j;
			}
		}
		tmp=tab[i];
		tab[i]=tab[imin];
		tab[imin]=tmp;
	}
}

void tri_insertion(int *tab, int taille) {
	int i, j, tmp;
	for(i = 0;i<taille;i++) {
		tmp = tab[i];
		j=i;
		while(j>0 && tab[j-1]>tmp) {
			tab[j]=tab[j-1];
			j--;
		}
		tab[j]=tmp;
	}
}

void tri_selection_recursif(int *tab, int taille){
	if(taille<2) return;
	int imin=0, j;
	for(j=1; j<taille; j++){
		if(tab[j]<tab[imin]){
			imin=j;
		}
	}
	int x = tab[imin]; tab[imin]=*tab; *tab=x;
	tri_selection_recursif(tab+1, taille-1);
}

int partition(int *tab, int debut, int fin, int indice_pivot)
{
	int p=tab[indice_pivot],i,j;
	tab[indice_pivot]=tab[fin];
	for (i=j=debut; i <= fin-1; i++)
	{
		if(tab[i]<p)
		{
			int x=tab[i]; tab[i]=tab[j]; tab[j++]=x;
		}
		//tab[debut ..j-1] contient les petits nombres
		//tab[j..fin-1] contient les grands nombrs
	}
	tab[fin]=tab[j];
	tab[j]=p;
	return j;
}

void tri_rapide(int *tab,int debut, int pivot, int fin)
{
	if(fin>debut){
	int j=partition(tab,debut,fin,pivot);
	tri_rapide(tab,debut,(j+debut)/2,j);
	tri_rapide(tab,j+1,(j+fin)/2,fin);}
}

void tri_cocktail( int *tab, int taille)
{
    int i, j, tmp;
    int stop;
    i = 0;
    do{

        stop = 1;

        for(j=0; j<taille-i-1; j++)
        {
            if( tab[j] > tab[j+1])
            {
                tmp = tab[j+1];
                tab[j+1] = tab[j];
                tab[j] = tmp;

                stop = 0;
            }
        }

        if( stop)
        {
            break;
        }

        stop = 1;

        for(j=n-2-i; j>i; j--)
        {
            if( tab[j-1] > tab[j])
            {
                tmp = tab[j];
                tab[j] = tab[j-1];
                tab[j-1] = tmp;
            }
        }

    }
}

void gnome_sort(int *tab,int taille)
{
	int i=0,temp;
	while (i<taille)
	{
		if (i==0 || tab[i]>=tab[i-1])
		{
			i=i+1;
		}
		else{
			temp=tab[i];
			tab[i]=tab[i-1];
			tab[i-1]=temp;
			i=i-1;
		}
	}
}


int main(int argc, char *argv[]) {
    int a=1, b=2;

    return 0;
}

// build/clang_ast_matcher exemples/file.c -- -I/home/l3c/Bureau/P/Projet_Harmo/libs/clang_llvm/lib/clang/3.9.1/include
