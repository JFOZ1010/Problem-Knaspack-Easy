function llenarMochila(pesoMaximo=0, pesos=[], valores=[]){
    let numIter = 0;
    let values = [];
    //TABLA DE RESULTADOS INTERMEDIOS: Valores máximos
    numIter++;
    values = pesos.map(v => Array.from({length:  pesoMaximo+1}, () => 0));
    for (let i=1; i<pesos.length; i++) {
        numIter++;
        for (let j=1; j<=pesoMaximo; j++){
            numIter++;
            if (i===1) {
                if (j>=pesos[i]) values[i][j] = valores[i];
            } else if (j<pesos[i]) {
                values[i][j] = values[i-1][j];
            } else {
                values[i][j] = Math.max(values[i-1][j], valores[i] + values[i-1][j-pesos[i]]);
            }
        }
    }
    //BUCLE VORAZ
    let objetos = [];
    let j = pesoMaximo;
    for (let i=pesos.length-1; i>0; i--){
        numIter++;
        if (values[i][j] !== values[i-1][j] && values[i][j] === values[i-1][j-pesos[i]] + valores[i]){
            objetos.push(i);
            j -= pesos[i];
        }
    }
    console.log(objetos)
    return objetos;
}

const pesos = [0,2,3,4,5]
const values = [0, 3,4,5,6]
llenarMochila(5, pesos, values); 