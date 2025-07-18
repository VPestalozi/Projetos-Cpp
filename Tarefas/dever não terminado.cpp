treenodeptr pMenor(treenodeptr arvore)
{
	treenodeptr t;
	t = arvore;
	if (t->esq == NULL) // encontrou o menor valor
	{
		arvore = arvore->dir;
		cout << t->info <<" e " <<endl;
		return t;
	}
	else // continua a busca na sub´arvore esquerda
		return pMenor(arvore->esq);
}

treenodeptr pMaior(treenodeptr arvore)
{
	treenodeptr m;
	m = arvore;
	if(m->dir == NULL)
	{
		arvore = arvore->esq;
		cout << m->info << endl;
		return m;
	}
	else
		return pMaior(arvore->dir);
}