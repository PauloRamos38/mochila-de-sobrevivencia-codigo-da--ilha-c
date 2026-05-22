# Mochila de Sobrevivência — Projetos em C

**Autor:** Paulo Ramos de Oliveira

Descrição
---------

Repositório com três desafios/programas em C (`mod1desafio.c`,
`mod2desafio.c`, `mod3desafio.c`) e um `main.c` launcher que permite
escolher qual módulo executar. O projeto foi preparado para evitar
múltiplos `main()` no mesmo binário — cada módulo foi convertido para
uma função `modX_main()` e o `main.c` seleciona o módulo a compilar via
macro.

Arquivos importantes
--------------------

- `mod1desafio.c`: implementação do Módulo 1 (`mod1_main()`).
- `mod2desafio.c`: implementação do Módulo 2 (`mod2_main()`).
- `mod3desafio.c`: implementação do Módulo 3 (`mod3_main()`).
- `main.c`: launcher que inclui o módulo selecionado e fornece o ponto
	de entrada único.
- `.gitignore`: ignora binários, a pasta `build/` e arquivos
	temporários.

Pré-requisitos (Windows)
------------------------

- Instalar MSYS2/MinGW (GCC) ou outro compilador compatível com C. Ex.:
	`C:/msys64/mingw64/bin/gcc.exe`.
- (Opcional) Git e GitHub CLI (`gh`) para operações no repositório
	remoto.

Compilar
-------

1) Compilar o `main.c` usando o módulo padrão (padrão: `mod3`):

```bash
gcc -g main.c -o main.exe
```

2) Compilar o `main.c` selecionando explicitamente um módulo (use a
macro `USE_MOD1` ou `USE_MOD2`):

```bash
gcc -DUSE_MOD1 -g main.c -o main_mod1.exe    # executável para mod1
gcc -DUSE_MOD2 -g main.c -o main_mod2.exe    # executável para mod2
gcc -DUSE_MOD3 -g main.c -o main_mod3.exe    # equivalente ao padrão
```

3) Compilar um módulo isolado (programa independente):

```bash
gcc -g mod1desafio.c -o mod1desafio.exe
gcc -g mod2desafio.c -o mod2desafio.exe
gcc -g mod3desafio.c -o mod3desafio.exe
```

Observação
---------

O repositório já contém versões dos módulos convertidas para
`modX_main()` para permitir `main.c` como launcher. Caso deseje manter
múltiplos executáveis independentes, compile os arquivos individuais,
por exemplo: `gcc mod1desafio.c -o mod1desafio.exe`.

Executar
-------

```powershell
.\main.exe
.\main_mod1.exe
.\mod2desafio.exe
```

Exemplo de teste automático (PowerShell)
--------------------------------------

```powershell
# Cria arquivo de entrada
$input = @"
1
Espada
arma
2
0
"@
Set-Content -Path test_input.txt -Value $input -Encoding UTF8
# Executa (PowerShell):
Get-Content test_input.txt | .\main.exe
# Remove artefatos
Remove-Item test_input.txt
```

Limpeza (remover binários temporários)
------------------------------------

```bash
rm -f *.exe
rm -rf build/
```

Git — boas práticas e push seguro
--------------------------------

- Confirme que o `.gitignore` está presente para evitar enviar
	binários ao remoto.
- Fluxo recomendado para enviar suas mudanças ao `origin/main` quando
	o remoto avançou:

```bash
git add <arquivos_modificados>
git commit -m "Descrição do que foi feito"
git fetch origin
git rebase origin/main
# Resolver conflitos se houver, depois:
git push origin main
```

Se o rebase reclamar de mudanças não rastreadas, use `git stash` para
guardar temporariamente:

```bash
git stash push -u -m "wip antes do rebase"
git rebase origin/main
git stash pop   # reaplica as mudanças locais
```

Tornar o repositório privado (GitHub)
-------------------------------------

Opção GUI: abra o repositório no GitHub → Settings → Change visibility
→ Make private.

Opção CLI (recomendado quando `gh` está autenticado):

```bash
gh auth login            # siga as instruções para autenticar
gh repo edit <OWNER>/<REPO> --visibility private
```

Exemplo para este repositório:

```bash
gh repo edit PauloRamos38/netlura.js --visibility private
```

Observação de segurança
----------------------

Não exponha documentos sensíveis (PDFs, scans, certificados). O
`git status` mostrou muitos arquivos fora do projeto — mantenha apenas
os arquivos do projeto no commit e remova ou ignore arquivos pessoais.

Sugestões extras
----------------

- Criar um `Makefile` simples para automatizar builds (posso gerar se
	desejar).
- Criar um `tests/` com arquivos de entrada e um script para rodar e
	validar saídas automaticamente.
- Revisar e remover arquivos grandes e pessoais do repositório (PDFs,
	executáveis, ISO), movendo-os para armazenamento seguro.

Se quiser, eu:

- gero um `Makefile` e um script de testes automatizados, ou
- faço o push das mudanças atuais (commit já preparado) e tento
	tornar o repo privado (se você autorizar a autenticação `gh`).
