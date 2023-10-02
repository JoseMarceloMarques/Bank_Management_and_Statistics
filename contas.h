typedef struct contas{
    int codigoCon;
    char tipo[10];
    float saldo;
    struct nodoMov *movimentos;
 }Conta;
 
 typedef struct nodoCon{
  Conta auxCon;
  struct nodoCon *next;
 }NodoCon;
 
Conta* procuraConta(Cliente *cliConta);
void guardarConta(NodoCon **listaCon, Conta dadosCon);
int existeConta(int codigoConta, NodoCli *listaCli);
void criarConta(Conta *dadosCon, NodoCli **listaCli);
void editarConta(NodoCli *listaCli);
void contaCli(NodoCli *listaCli);
void removerConta(NodoCli **listaCli);
void listarContasCliente(NodoCli *listaCli);
int contaOrdem(Cliente **cliente, NodoCli *listaCli);
int contaPrazo(Cliente **cliente, NodoCli *listaCli);
