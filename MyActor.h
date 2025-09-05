// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

//������(0, 0) �ִ� ���� ĳ���Ͱ� �����ϰ� 10ȸ �̵� �մϴ�.
// �� ���ܿ��� ���İ� ��ǥ�� ��� ����ϴ°� �����Դϴ�.
//
//���� �䱸������ �Ʒ��� �����ϴ�.
//
//- ��������(0, 0)�̰� �ѹ� �̵��� x��ǥ�� y��ǥ ��� 2�̻� �̵��� �� �����ϴ�.���� ��� �Ʒ��� �����ϴ�.
//- (0, 0) ����(1, 2)�� �̵��Ҽ� �����ϴ�.y��ǥ�� 2�̻� �̵��߱� �����Դϴ�.
//- (0, 0)����(1, 1)�� �̵��� �� �ֽ��ϴ�.x��ǥ  y��ǥ ��� 2�̸� �̵��߱� ���� �Դϴ�.


//- �̵��� �Է��� �޴°� �ƴϰ� 10ȸ ��� �������� �����Դϴ�.
//- �Ź� �̵��� ���� ��ǥ�� ����� �� �־�� �մϴ�.
//- �α� ����� UE_LOG�� Ȱ���մϴ�.
 

//- step �Լ��� x��ǥ y��ǥ ���� �̵��� �Ÿ� �Դϴ�.
//- ������ ���� ��ǥ��(x1, y1)�̶�� ���� ��ǥ��(x1 + step �Լ��� ���ϰ�, y1 + step�Լ��� ���� ��) �Դϴ�.
//- step�Լ��� 0Ȥ�� 1�� �������� ��ȯ �մϴ�.

//- move�Լ���(0, 0)���� 10ȸ �����̸鼭 ��ǥ�� ����մϴ�.�̵��� step �Լ��� Ȱ�� �˴ϴ�.

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
	//��� ������ �ʿ��� ������� (Ŭ������ �Ӽ�)
	//��ǥ
	FVector2D CurrentLocation; //������ġ�� ��� ��ǥ
	FVector2D PreviousLocation;

	float TotalDistance;
	int32 TotalEventCount;   

	//��� ������ �ʿ��� ����Լ� (Ŭ������ ���)
	int32 Step();
	void Move(int32 MoveCount, float Proability);
	void TriggerEventWithProability(float proability);
	float Distance(FVector2D second, FVector2D first); 
	//����ϴ� ���� move --> ��ȯ�� �ʿ� X

};
