#include <stdio.h>
#include <stdlib.h>

typedef struct fraccion{
    int numerador;
    int denominador;
} fraccion;

void menuPrincipal(void);
void subMenu(void);
fraccion suma(fraccion x, fraccion y);
fraccion resta(fraccion x, fraccion y);
fraccion multiplicacion(fraccion x, fraccion y);
fraccion division(fraccion x, fraccion y);
fraccion escanearFraccion(void);
void escanearFracciones(void);

fraccion simplificar(fraccion x);
int mcd(int numero1, int numero2);

fraccion fraccionUno;
fraccion fraccionDos;
fraccion resultado;

int main(int argc, const char * argv[]) {
    menuPrincipal();
    return 0;
}

void menuPrincipal(){
    int opc = 0;
    printf("Fracciones\n");
    printf("Operaciones:\n");
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. Multiplicacion\n");
    printf("4. Division\n");
    printf("5. Numerador\n");
    printf("6. Denominador\n");
    printf("7. Salir\n");
    printf("Digite una opcion\n");
    printf("\n");
    scanf("%d", &opc);
    
    switch (opc) {
        case 1://suma
            escanearFracciones();
            resultado = suma(fraccionUno, fraccionDos);
            printf("Resultado de la suma: %d/%d\n", resultado.numerador, resultado.denominador);
            break;
        case 2://resta
            escanearFracciones();
            resultado = resta(fraccionUno, fraccionDos);
            printf("Resultado de la resta: %d/%d\n", resultado.numerador, resultado.denominador);
            break;
        case 3://multiplicacion
            escanearFracciones();
            resultado = multiplicacion(fraccionUno, fraccionDos);
            printf("Resultado de la multiplicacion: %d/%d\n", resultado.numerador, resultado.denominador);
            break;
        case 4://division
            escanearFracciones();
            resultado = division(fraccionUno, fraccionDos);
            printf("Resultado de la division: %d/%d\n", resultado.numerador, resultado.denominador);
            break;
        case 5://numerador
        	resultado = escanearFraccion();
        	printf("El numerador de la fraccion es: %d\n", resultado.numerador);
        	break;
        case 6://denominador
        	resultado = escanearFraccion();
        	printf("El denominador de la fraccion es: %d\n", resultado.denominador);
        	break;
        case 7://salir
            exit(0);
            break;
        default:
            printf("Elija una opcion del menu\n");
            menuPrincipal();
            break;
    }
    subMenu();
}

void subMenu(){
    char eleccion = ' ';
    printf("Presione s para simplificar la fraccion\n");
    printf("Presione m para regresar al menu\n");
    printf("Presione x para salir\n");
    scanf(" %c", &eleccion);
    switch(eleccion){
        case 's':
            resultado=simplificar(resultado);
            printf("Resultado de la simplificacion: %d/%d\n", resultado.numerador, resultado.denominador);
            menuPrincipal();
            break;
        case 'm':
            menuPrincipal();
            return;
            break;
        case 'x':
            exit(0);
            break;
        default:
            printf("Elija una opcion del menu\n");
            subMenu();
            break;
    }
}

fraccion suma(fraccion x, fraccion y){
    int denominadorFinal = x.denominador * y.denominador;
    int productoUno = x.numerador * y.denominador;
    int productoDos = x.denominador * y.numerador;
    int numeradorFinal = productoUno + productoDos;
    fraccion resultado;
    resultado.numerador = numeradorFinal;
    resultado.denominador = denominadorFinal;
    return resultado;
}

fraccion resta(fraccion x, fraccion y){
    int denominadorFinal = x.denominador * y.denominador;
    int productoUno = x.numerador * y.denominador;
    int productoDos = x.denominador * y.numerador;
    int numeradorFinal = productoUno - productoDos;
    fraccion resultado;
    resultado.numerador = numeradorFinal;
    resultado.denominador = denominadorFinal;
    return resultado;
}

fraccion multiplicacion(fraccion x, fraccion y){
    int numeradorFinal = x.numerador * y.numerador;
    int denominadorFinal = x.denominador * y.denominador;
    fraccion resultado;
    resultado.numerador = numeradorFinal;
    resultado.denominador = denominadorFinal;
    return resultado;
}

fraccion division(fraccion x, fraccion y){
    int numeradorFinal = x.numerador * y.denominador;
    int denominadorFinal = x.denominador * y.numerador;
    fraccion resultado;
    resultado.numerador = numeradorFinal;
    resultado.denominador = denominadorFinal;
    return resultado;
}

fraccion escanearFraccion(){
    int numerador, denominador;
    printf("Digite el numerador de la fraccion:\n");
    scanf("%d", &numerador);
    printf("Digite el denominador de la fraccion:\n");
    scanf("%d", &denominador);
    if(denominador != 0){
        fraccion resultado;
        resultado.numerador = numerador;
        resultado.denominador = denominador;
        return resultado;
    }
    else{
        printf("El denominador debe de ser distinto de cero\n");
        return escanearFraccion();
    }
}

fraccion simplificar(fraccion x){
    int max=mcd(x.numerador, x.denominador);
    int num=x.numerador/max;
    int den=x.denominador/max;
    fraccion resultado;
    resultado.numerador=num;
    resultado.denominador=den;
    return resultado;
}

int mcd(int numero1, int numero2){
    int resultado = 0;
    int x, y;
    if(numero1 > numero2){
        x = numero1;
        y = numero2;
    }
    else{
        x = numero2;
        y = numero1;
    }
    
    do{
        resultado = y;
        y = x%y;
        x = resultado;
    }while(y!=0);
    
    return resultado;
}

void escanearFracciones(){
    printf("Primera fraccion\n");
    fraccionUno = escanearFraccion();
    printf("Segunda fraccion\n");
    fraccionDos = escanearFraccion();
}
