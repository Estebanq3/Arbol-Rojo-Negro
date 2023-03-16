La primer pregunta elaboro el arbol correspondiente al enunciado, a la hora de escanear 
la hoja se cortan un poco algunos numeros pero, esos numeros que se cortan es el 1.
Detallo todos los pasos para llegar al arbol final equilibrado con todos los elementos de la lista
añadidos.
Posteriormente en la segunda pregunta, se elabora la rotación doble derecha. Simplemente
lo añado en la parte correspondiente y agrego el recoloreo.
Esta pregunta se ejecuta con g++ -o prueba main.cpp
En la tercer pregunta ya la clase árbol se encuentra toda en un .h por lo tanto solo agrego el
template y cambio los int y demás indentificadores por la K de Key, llave, y la V de Value, valor
Luego para compilar se utiliza el mismo comando que el de la segunda pregunta
es decir: g++ -o prueba main.cpp
La cuarta pregunta utilizo la ayuda de CplusPlus para poder investigar el funcionamiento
de map, una plantilla de un árbol, y agrego un for con un iterador que recorre el contenedor
imprimiendo sus valores requeridos.
Se compila con g++ -o prueba main.cpp
La quinta pregunta elaboro dos clases letra y entero las cuales son hijas de Valor, el cual
se sustituirá por la plantilla de la pregunta anterior para optimizarlo
De esta forma se puede llegar a utilizar el main polimórfico, ya que tenemos un arbol polimorfico.
El tipo del valor es Polimórfico y acepta tanto instancias de Entero como de Letra.
El árbol admite mezclas de ambos tipos de valor en la misma instancia de árbol, cosa que no permiten las plantillas.
Se compila con g++ -o prueba mainPolimorfico.cpp letra.cpp entero.cpp