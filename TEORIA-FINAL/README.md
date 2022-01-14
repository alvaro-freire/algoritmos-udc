# FINAL TEORÍA -> 12 ENERO 2022

### EJERCICIO 1 (*2.5 puntos*):

#### Diccionario de datos:

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

#### *hash*("a", 11) = 8
#### *hash*("b", 11) = 7
#### *hash*("c", 11) = 7
#### *hash*("d", 11) = 7
#### *hash*("e", 11) = 8
#### *hash*("f", 11) = 8

#### muestre el resultado de insertar las claves: "a", "b", "c", "d", "e" y "f" (en ese orden) en la siguiente tabla:


| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
| -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- |
| _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |

#### cuando se emplea:

##### 1) exploración lineal
##### 2) exploración cuadrática
##### 3) exploración doble usando 5 - (x *mod* 5) como segunda función (siendo *x* el resultado de la primera función).

#### Indique asímismo el número total de colisiones que se produce durante las inserciones en cada una de las tres exploraciones.

### EJERCICIO 2 (*2 puntos*):

#### Compare la *ordenación por fusión* con la *ordenación rápida* desde el punto de vista del diseño del algoritmo (técnica de diseño, fases de la técnica utilizada, estrategias para la mejora del tiempo de ejecución...) así como de su complejidad (relaciones de recurrencia según cada caso, que se justificarán y se resolverán, teorema necesario para resolverlas...).

### EJERCICIO 3 (*2.5 puntos*):

#### Dado el algoritmo siguiente:

```pseudo
función Kruskal ( G = { N, A } ) : tipo:salida {1}
    Organizar los candidatos a partir de A; {2}
    n := |N|; T := conjunto vacío; peso := 0;
    inicializar n conjuntos, cada uno con un nodo de N;
    repetir
        Seleccionar y extraer un candidato a; {3}
        ConjuntoU := Buscar (a.nodo1); ConjuntoV := Buscar (a.nodo2);
        si ConjuntoU <> ConjuntoV entonces
            Fusionar (ConjuntoU, ConjuntoV);
            T := T U {a};
            peso := peso + a.peso;
        fin si
    hasta |T| = n-1;
    devolver <T, peso>
fin función
```

##### a) Precise el tipo de datos de la salida de la función ({1}).

##### b) Reescriba las instrucciones {2} y {3} introduciendo el uso de un montículo, decisión que justificará en su respuesta.

##### c) Enuncie de forma precisa el problema que resuelve este algoritmo.

##### d) Concrete los elementos característicos de la técnica voraz que correspondan a este ejemplo.

##### e) Análisis detallado de la complejidad.
