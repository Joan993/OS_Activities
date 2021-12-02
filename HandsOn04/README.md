## Q1: Repetir els passos amb l'ordre yes > /dev/null. Què fa aquesta ordre? Quines diferències trobeu amb l'execució de l'ordre anterior? (0,5 punts)


La orden hace que utilice todos los ciclos de la CPU para un solo núcleo.En la primera ejecucion el estado era de (R - running or runnable (on run queue)).Al parar el proceso el estado del proceso es de (T - stopped by job control signal).Y al volver a iniciarlo con bg el estado vuelve a ser de (R - running or runnable (on run queue))

**Correcció**:
L'ordre ```yes``` simplement escriu repetidament una cadena a stdout, el caràcter *y* per defecte. Redirigint-lo (>) a **/dev/null**. 

## Q2: Modificar aquest procés per obtenir una sortida indicant Hola sóc el procés pare i Hola sóc el procés fill. (0,5 punts)

Aquest apartat s'ha solucionat al fitxer **act02.c**

## Q3: Modificar aquest exemple fent anar la funció execv(). (0,5 punts)
 
```c
// Original:
// execvp( "find", argv );
// Solució:
execv( "/usr/bin/find", argv );
```
**Correcció:**
Has utilitzat ls però demanava amb find ^^.

## Q4: Explica el funcionament del programa. Indicant quants senyals s'envien, quin procés envia el senyal, i on l'envia. (2,5 punts)

Lo que hace es primero pasar por el primera condicion ya que es la del padre, sale por pantalla el manesage del padre y 
el fflush vaciar el buffer, luego con el waitpid, el proceso padre se pausa para dar paso al proceso hijo a que se ejecute, saliendo por pantalla un saludo.

Luego el proceso hijo se termina machacandolo con kill con sigstop y vuelve al proceso padre, en donde se hace un print y otro 
kill para el padre donde esta vez al kill tiene sigcont, que hace que vuelve al proceso hijo terminado anteriormente.

Luego ya terminado salido del if y terminando el programa

**Correcció**:
El kill no acaba el procés li envia un senyal.
En total s'envien 5 senyals. Els canvis d'estat del fill generats per SIGCON i SIGSTOP generen el senyal SIGCHL que notifica el pare d'aquest events. L'ordre ```exit()```també la genera.

## Q5: Programeu un programa pare, fill net que tingui la següent sortida (mantenint l’ordre). A més a més els fills, hauran de generar un enter aleatori entre els valors 0,1 i 2. El 0=apunyalat, 1=decapitat.  (4 punts)

Aquest apartat s'ha solucionat al fitxer **act05.c**


