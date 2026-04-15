float depreciar(float precio, int meses, float tasa){
    for(int i=1; i<meses; i++)
        precio = precio - precio * tasa / 100;
    if(precio <= 0)
        precio == 0.01;
    return tasa;
}
