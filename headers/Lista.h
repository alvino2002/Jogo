#pragma once

namespace Masmorra
{
	namespace Listas
	{
		template <class TipoLista> class Lista
		{
		public: // Elemento dentro de lista
			template <class TipoElemento> class Elemento
			{
			private:
				Elemento <TipoElemento>* pProx;
				TipoElemento* pInfo;

			public:
				Elemento()
				{
					pProx = nullptr;
					pInfo = nullptr;
				}
				~Elemento()
				{
					pProx = nullptr;
					pInfo = nullptr;
				}
				void setProx(Elemento <TipoElemento>* pProx)
				{
					this->pProx = pProx;
				}
				Elemento <TipoElemento>* getProx()
				{
					return pProx;
				}
				void setInfo(TipoElemento* pInfo)
				{
					this->pInfo = pInfo;
				}
				TipoElemento* getInfo()
				{
					return pInfo;
				}
			};

		private:
			unsigned int tam;
			Elemento <TipoLista>* pPrim;
			Elemento <TipoLista>* pUlt;

		public:
			Lista();
			~Lista();
			void clear();
			unsigned int getTam();
			void push(TipoLista* pInfo);
			void pop(TipoLista* pInfo);
			//TipoLista* remove(TipoLista* pInfo);
			TipoLista* getpInfo(int posicao);
		};

		template <class TipoLista>
		Lista<TipoLista>::Lista() : // Construtora
			tam(0)
		{
			pPrim = nullptr;
			pUlt = nullptr;
		}

		template <class TipoLista>
		Lista<TipoLista>::~Lista() // Destrutora
		{
			clear();
			pPrim = nullptr;
			pUlt = nullptr;
		}

		template <class TipoLista>
		unsigned int Lista<TipoLista>::getTam() // Tamanho da lista
		{
			return tam;
		}

		template <class TipoLista>
		void Lista<TipoLista>::clear() // Limpar a lista
		{
			Elemento<TipoLista>* aux1 = pPrim;
			Elemento<TipoLista>* aux2 = nullptr;

			while (aux1 != nullptr)
			{
				aux2 = aux1->getProx();

				if (aux1->getInfo())
				{
					delete aux1->getInfo();
					aux1->setInfo(nullptr);
				}

				delete aux1;
				aux1 = aux2;
			}

			pPrim = nullptr;
			pUlt = nullptr;
			tam = 0;
		}

		template <class TipoLista>
		void Lista<TipoLista>::push(TipoLista* pInfo) // Adicionar elemento
		{
			if (pPrim == nullptr) // Primeiro elemento?
			{
				pPrim = new Elemento<TipoLista>;
				pPrim->setInfo(pInfo);
				pUlt = pPrim;
			}
			else
			{
				Elemento<TipoLista>* temp = new Elemento<TipoLista>;
				temp->setInfo(pInfo);
				pUlt->setProx(temp);
				pUlt = temp;
			}
			tam++;
		}

		template <class TipoLista>
		void Lista<TipoLista>::pop(TipoLista* pInfo) // Remover elemento
		{
			Elemento<TipoLista>* aux1 = pPrim;
			Elemento<TipoLista>* aux2 = nullptr;

			while (aux1->getInfo() != pInfo) // Buscando
			{
				aux2 = aux1;
				aux1 = aux1->getProx();
			}
			if (aux1 == pPrim) // Remover o primeiro elemento
			{
				pPrim = aux1->getProx();
			}
			else if (aux1 == pUlt) // Remover o ultimo elemento
			{
				aux2->setProx(nullptr);
				pUlt = aux2;
			}
			else
			{
				aux2->setProx(aux1->getProx());
			}
			delete aux1;

			tam--;
		}

		/*template <class TipoLista>
		TipoLista* Lista<TipoLista>::remove(TipoLista* pInfo)
		{
			Elemento<TipoLista>* aux1 = pPrim;
			Elemento<TipoLista>* aux2 = nullptr;

			while (aux1->getInfo() != pInfo)
			{
				aux2 = aux1;
				aux1 = aux1->getProx();
			}
			if (aux1 == pPrim)
			{
				pPrim = aux1->getProx();
			}
			else if (aux1 == pUlt)
			{
				aux2->setProx(nullptr);
				pUlt = aux2;
			}
			else
			{
				aux2->setProx(aux1->getProx());
			}

			TipoLista* retorno = aux1->getInfo();
			delete aux1;
			tam--;
			return retorno;
		}*/

		template <class TipoLista>
		TipoLista* Lista<TipoLista>::getpInfo(int posicao) // Retornar um elemento dado a posicao
		{
			Elemento<TipoLista>* aux1 = pPrim;

			if (posicao == 0)
			{
				return aux1->getInfo();
			}
			else
			{
				for (int i = 0; i < posicao; i++)
				{
					if (aux1)
					{
						aux1 = aux1->getProx();
					}
				}
				return aux1->getInfo();
			}
		}
	}
}
