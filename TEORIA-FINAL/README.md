# FINAL TEORÍA -> 12 ENERO 2022

## EJERCICIO 1:

### (2.5 puntos) Diccionario de datos:

#### a) Diseñe, escribiendo su pseudocódigo, los algoritmos *inicializarTabla*, *insertar*, *buscar*, y *eliminar* usando *exploración cuadrática*, de modo que las tres últimas rutinas se ejecuten en un tiempo promedio constante. Usa la siguiente declaración de tipos:

```pseudo
tipo
    ClaseDeEntrada = (legítima, vacía, borrada)
    Índice = 0..N-1
    Posición = Índice
    Entrada = registro
        Elemento : TipoElemento
        Información : ClaseDeEntrada
    fin registro
    TablaDispersión = vector {Índice} de Entrada
```

#### Si utilizase algún procedimiento auxiliar (distinto de la función *hash*), refleje también su pesudocódigo.


#### b) Con la siguiente función *hash*:
