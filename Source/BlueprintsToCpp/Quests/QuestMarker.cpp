// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestMarker.h"
#include "NiagaraComponent.h"

// Sets default values
AQuestMarker::AQuestMarker(){
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	NiagaraSystem = CreateDefaultSubobject<UNiagaraComponent>(TEXT("NiagaraSystem"));

	SetRootComponent(Root);
	NiagaraSystem->SetupAttachment(Root);

	// Wasn't able to set user parameters from Blueprint, which is frustrating.
	NiagaraSystem->SetVariableVec3(TEXT("Vector (RGB)_Color"), FVector3d{ 1.0, 0.0, 0.090841 });
}

void AQuestMarker::RefreshVisibility()
{
	FQuestInfo Quest = GetQuestManager()->GetQuest(QuestName);
	bool Visibility = GetQuestManager()->IsActiveQuest(QuestName) && Quest.Progress == ShowAtProgress;
	NiagaraSystem->SetVisibility(Visibility);


}


