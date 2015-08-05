//class mainCharacter model1;
//class mainCharacter model2;
//class mainCharacter model3;
//class mainCharacter model4;
//class mainCharacter model5;
//class mainCharacter model6;
//class mainCharacter model7;
//class mainCharacter model8;
//class mainCharacter model9;

void declareMainChara(std::size_t nModels){
	for(std::size_t iModel=0;iModel<nModels;iModel++){
		ListOfModelsReferences.push_back(mainCharacter());
	}
};

void declareMonster1(std::size_t nModels){
	for(std::size_t iModel=0;iModel<nModels;iModel++){
		ListOfModelsReferences.push_back(monster1());
	}
};

void declareCatGirl(std::size_t nModels){
	for(std::size_t iModel=0;iModel<nModels;iModel++){
		ListOfModelsReferences.push_back(catGirl());
	}
};