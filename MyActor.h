// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

//시작점(0, 0) 있는 게임 캐릭터가 랜덤하게 10회 이동 합니다.
// 각 스텝에서 거쳐간 좌표를 모두 출력하는게 목적입니다.
//
//세부 요구사항은 아래와 같습니다.
//
//- 시작점은(0, 0)이고 한번 이동시 x좌표와 y좌표 모두 2이상 이동할 수 없습니다.예를 들면 아래와 같습니다.
//- (0, 0) 에서(1, 2)은 이동할수 없습니다.y좌표가 2이상 이동했기 때문입니다.
//- (0, 0)에서(1, 1)은 이동할 수 있습니다.x좌표  y좌표 모두 2미만 이동했기 때문 입니다.


//- 이동은 입력을 받는게 아니고 10회 모두 랜덤으로 움직입니다.
//- 매번 이동시 현재 좌표를 출력할 수 있어야 합니다.
//- 로그 출력은 UE_LOG를 활용합니다.
 

//- step 함수는 x좌표 y좌표 각각 이동할 거리 입니다.
//- 예를들어서 현재 좌표가(x1, y1)이라면 다음 좌표는(x1 + step 함수의 리턴값, y1 + step함수의 리턴 값) 입니다.
//- step함수는 0혹은 1을 랜덤으로 반환 합니다.

//- move함수는(0, 0)부터 10회 움직이면서 좌표를 출력합니다.이동시 step 함수가 활용 됩니다.

UCLASS()
class HW05_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	//기능 구현에 필요한 멤버변수 (클래스의 속성)
	//좌표
	FVector2D CurrentLocation; //현재위치를 담는 좌표
	FVector2D PreviousLocation;

	float TotalDistance;
	int32 TotalEventCount;   

	//기능 구현에 필요한 멤버함수 (클래스의 기능)
	int32 Step();
	void Move(int32 MoveCount, float Proability);
	void TriggerEventWithProability(float proability);
	float Distance(FVector2D second, FVector2D first); 
	//출력하는 역할 move --> 반환할 필요 X

};
