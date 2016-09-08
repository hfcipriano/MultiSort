typedef struct NODE{
        int     valor;
        struct  NODE *proximo;
        struct  NODE *anterior;
        void    (*printNode)();
}node;
typedef struct LISTA{
        node    *raiz;
	node	*folha;
        int     qtd;
        void    (*printListaTexto)();
        void    (*printListaBin)();
        void    (*addNodeInicio)();
        void    (*addNodeFinal)();
	    void 	(*desconectaNode)();
        node*   (*rmNodeFinal)();
	node*	(*swap)();
	int	(*verificar)();
}lista;

