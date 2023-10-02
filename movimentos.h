typedef struct movimentos{
    char data[10];
    char tipo[10];
    float valor;
 }Movimento;
 
 typedef struct nodoMov{
  Movimento auxMov;
  struct nodoMov *next;
 }NodoMov;
 
 
void guardarMovimento(NodoMov **listaMov, Movimento dadosMov);
void devolveData(char* dataAtual);
void criarDepositoOrdem(Movimento *dadosMov, NodoCli **listaCli, Cliente *cliente);
void criarDepositoPrazo(Movimento *dadosMov, NodoCli **listaCli, Cliente *cliente);
void criarLevantamentoOrdem(Movimento *dadosMov, NodoCli **listaCli, Cliente *cliente);
void criarLevantamentoPrazo(Movimento *dadosMov, NodoCli **listaCli, Cliente *cliente);
void listaMovimento(NodoCli *listaCli);
 
