#include <stdio.h>

typedef struct fraccion{
    int numerador;
    int denominador;
} fraccion;

fraccion suma(fraccion x, fraccion y);
fraccion resta(fraccion x, fraccion y);
fraccion multiplicacion(fraccion x, fraccion y);
fraccion division(fraccion x, fraccion y);
fraccion escanearFraccion(void);
void escanearFracciones(void);

fraccion fraccionUno;
fraccion fraccionDos;
fraccion resultado;

int main(int argc, const char * argv[]) {
    int opc = 0;
    printf("Fracciones\n");
    printf("Operaciones:\n");
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. Multiplicacion\n");
    printf("4. Division\n");
    printf("5. Simplificacion\n");
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
        default://simplificacion
            break;
    }
    return 0;
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

void escanearFracciones(){
    printf("Primera fraccion\n");
    fraccionUno = escanearFraccion();
    printf("Segunda fraccion\n");
    fraccionDos = escanearFraccion();
}
