typedef struct cliente{
	long codigoCli;
	char nome[50];
	char morada[50];
	float saldo;
	struct nodoCon *contas;
} Cliente;
		
typedef struct nodoCli{
	Cliente auxCli;            
	struct nodoCli *next;      
} NodoCli;

Cliente* procuraCliente(NodoCli *listaCli);
void dadosCliente(Cliente *dadosCli);
int existeCliente(long codigoCliente, NodoCli *listaCli);
void guardarCliente(NodoCli **listaCli, Cliente dadosCli);
void editarCliente(NodoCli *listaCli);
void saldoGlobalCliente(NodoCli *listaCli);
void removerCliente(NodoCli **listaCli);
void listarClientes(NodoCli *listaCli);
