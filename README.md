# PRÁCTICAS ALGORITMOS 2021/22

## Suma de Subsecuencia Máxima (Divide y vencerás)

### Pseudocódigo

```pseudo
función SumaSubMax3 (v[1..n])
    devolver SumaSubMaxAux (v, 1, n)
fin función

función SumaSubMaxAux (v[1..n], izq, der)
    si izq = der entonces
        si v[izq] > 0 entonces devolver v[izq]
        fin si
    sino
        centro := (izq + der) div 2 ;
        sumDer := SumaSubMaxAux (v, centro + 1, der) ;
        sumIzq := SumaSubMaxAux (v, izq, centro) ;
        sumBordeDer := 0 ;
        sumAux := 0 ;
        para i := centro + 1 hasta der hacer
            sumAux := sumAux + v[i] ;
            si sumAux > sumBordeDer entonces
                sumBordeDer := sumAux
            fin si
        fin para
        sumBordeIzq := 0 ;
        sumAux := 0 ;
        para j := centro hasta izq paso -1 hacer
            sumAux := sumAux + v[j] ;
            si sumAux > sumBordeIzq entonces
                sumBordeIzq := sumAux
            fin si
        fin para ;
        devolver max(max(sumIzq, sumDer), sumBordeIzq + sumBordeDer)
    fin si
fin función
```

### Ejercicio 1:

#### 1. Copie de las prácticas realizadas los ficheros que estime oportunos.

#### 2. Implemente en C el algoritmo propuesto; realice la implementación tomando como modelo el siguiente código:

```c

int sumaSubMaxAux(int v[], int izq, int der) {
    {...}
}

int sumaSumMax3(int v[], int n) {
    return sumaSubMaxAux(v, 0, n - 1);
}
```
#### 3. TODO

#### 4. TODO

#### 5. TODO
