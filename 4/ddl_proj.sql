CREATE TABLE Destaque (
	id_destaque int UNIQUE NOT NULL,
	data_validade datetime,
	PRIMARY KEY (id_destaque)
);

CREATE TABLE Buscar (
	fk_edital_fk_tipo_de_match int,
	fk_destaque_id_destaque int,
	PRIMARY KEY (fk_edital_fk_tipo_de_match, fk_destaque_id_destaque),
	FOREIGN KEY (fk_edital_fk_tipo_de_match) REFERENCES Edital(fk_tipo_de_match_id_tipo),
	FOREIGN KEY (fk_destaque_id_destaque) REFERENCES Destaque (id_destaque)
);

CREATE TABLE Startup (
	id_startup int UNIQUE NOT NULL,
	nome varchar (50),
	faturamento float,
	tipo_inscricao varchar (100), 
	n_documento int,
	quantidade_membros int,
	idade int,
	area varchar (100), 
	disponibilidade_fisica bool, 
	PRIMARY KEY (id_startup)
);

CREATE TABLE Visualizar (
	fk_startup_id_startup int,
	fk_destaque_id_destaque int,
	FOREIGN KEY (fk_startup_id_startup) REFERENCES Startup(id_startup),
	FOREIGN KEY (fk_destaque_id_destaque) REFERENCES Destaque(id_destaque)
);

CREATE TABLE Edital (
    data_validade datetime,
    codigo_edital int UNIQUE NOT NULL,
    fk_tipo_de_match_id_tipo int,
    PRIMARY KEY (codigo_edital),
    FOREIGN KEY (fk_tipo_de_match_id_tipo) REFERENCES TipoDeMatch (id_tipomatch)
);

CREATE TABLE Match_ (
    id_match int UNIQUE NOT NULL,
    fk_tipo_de_match_id_tipo int,
	fk_startup_id_startup int,
    PRIMARY KEY (id_match),
	FOREIGN KEY (fk_startup_id_startup)  REFERENCES Startup(id_startup),
    FOREIGN KEY (fk_tipo_de_match_id_tipo) REFERENCES TipoDeMatch (id_tipomatch)
); 

CREATE TABLE TipoDeMatch (
    id_tipomatch int UNIQUE NOT NULL,
    faturamento_min float,
    faturamento_max float,
    tipo_inscricao varchar(100),
    quantidade_min_membros int,
    quantidade_max_membros int,
    area varchar(100),
    idade_min int,
    idade_max int,
    PRIMARY KEY (id_tipomatch)
);

CREATE TABLE Gerar (
    fk_match_id_match int,
    fk_lista_de_matches_id_match int,
    FOREIGN KEY (fk_lista_de_matches_id_match) REFERENCES ListaDeMatches (id_match),
    FOREIGN KEY (fk_match_id_match) REFERENCES Match_ (id_match)
);

CREATE TABLE Investidor (
    cpf varchar(11) UNIQUE NOT NULL,
    nome varchar(50),
    fk_tipo_de_match_id_tipo int,
    FOREIGN KEY (fk_tipo_de_match_id_tipo) REFERENCES TipoDeMatch (id_tipomatch)
);

CREATE TABLE Empresa (
    razao_social varchar(50),
    cnpj varchar(50) UNIQUE NOT NULL,
    fk_tipo_de_match_id_tipo int,
    FOREIGN KEY (fk_tipo_de_match_id_tipo) REFERENCES TipoDeMatch(id_tipomatch)
);

CREATE TABLE Privado (
    razao_social varchar(50),
    cnpj varchar(50) UNIQUE NOT NULL,
    fk_edital_fk_tipo_de_match int,
    FOREIGN KEY (fk_edital_fk_tipo_de_match) REFERENCES TipoDeMatch(id_tipomatch)
);

CREATE TABLE Publico (
    organizacao varchar(50),
    fk_edital_fk_tipo_de_match int,
    FOREIGN KEY  (fk_edital_fk_tipo_de_match) REFERENCES TipoDeMatch(id_tipomatch)
);

CREATE TABLE ListaDeMatches (
	id_match int UNIQUE NOT NULL,
    validado datetime,
    PRIMARY KEY (id_match)
);

CREATE TABLE Validar (
	fk_funcionario_Dates_id_funcionario int,
	fk_lista_de_matchs_id_match int,
    FOREIGN KEY (fk_funcionario_Dates_id_funcionario) REFERENCES FuncionarioDates (ID_funcionario),
    FOREIGN KEY (fk_lista_de_matchs_id_match) REFERENCES ListaDeMatches (id_match)
);

CREATE TABLE FuncionarioDates (
    cpf varchar(50) UNIQUE NOT NULL,
    nome varchar(50),
    ID_funcionario int UNIQUE NOT NULL,
    PRIMARY KEY (ID_funcionario)
);