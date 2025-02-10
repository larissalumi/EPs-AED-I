#include <stdio.h>

int main (){
	int ricardo, vicente, cont, resultado = 0, casos;

	scanf("%d", &casos);

    for (cont = 0; cont < casos; cont++){
        scanf("%d %d", &ricardo, &vicente);

		while (vicente != 0){
			resultado = ricardo % vicente;
			ricardo = vicente;
			vicente = resultado;
		}

		printf("%d\n", ricardo);

    }
    return 0;
}