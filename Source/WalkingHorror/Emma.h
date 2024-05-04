// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Serialization/Archive.h"
#include "GameFramework/Character.h"
#include "Emma.generated.h"


class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS()
class WALKINGHORROR_API AEmma : public ACharacter
{
	GENERATED_BODY()

	/* Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/* Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* CrouchAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* SaveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LoadAction;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	bool isCrouching;

public:
	// Sets default values for this character's properties
	AEmma();

	/* Returns CameraBoom subobject */
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	/* Returns FollowCamera subobject */
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Move(const FInputActionValue& Value);

	void Look(const FInputActionValue& Value);

	void Crouch(const FInputActionValue& Value);

	void Save(const FInputActionValue& Value);

	void Load(const FInputActionValue& Value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	// Serialize the actor's data
	void Serialize(FArchive& Ar)
	{
		Super::Serialize(Ar); // Call the base class serialize to handle parent class data
		
		// Log to the console
		UE_LOG(LogTemp, Warning, TEXT("Serialize: Character Saved."));

		// Serialize the actor's current location to the archive
		FVector Location = GetActorLocation();
		Ar << Location; // Using the << operator to write the FVector to the archive
	}

	// Deserialize the actor's data
	void Deserialize(FArchive& Ar)
	{
		// Log to the console
		UE_LOG(LogTemp, Warning, TEXT("Deserialize: Character Loaded."));

		FVector Location;
		Ar << Location; // Using the << operator to read the FVector from the archive
		SetActorLocation(Location); // Update the actor's location with the deserialized value
	}

	// Function to save the character's location to a file
	void SaveCharacterLocation(AEmma* Character)
	{
		// Log to the console
		UE_LOG(LogTemp, Warning, TEXT("SaveCharacterLocation: Save Character Location."));

		if (!Character)
			return; // Ensure the character pointer is valid

		// Define the file path for saving the location
		FString SavePath = FPaths::ProjectDir() / TEXT("Saved") / TEXT("CharacterLocation.sav");
		// Create a file writer object to write the data
		FArchive* FileArchive = IFileManager::Get().CreateFileWriter(*SavePath);
		if (FileArchive)
		{
			Character->Serialize(*FileArchive); // Serialize the character's location to the file
			FileArchive->Close(); // Close the file to finalize writing
			delete FileArchive; // Clean up the file archive object
		}
	}

	// Function to load the character's location from a file
	void LoadCharacterLocation(AEmma* Character)
	{
		// Log to the console
		UE_LOG(LogTemp, Warning, TEXT("LoadCharacterLocation: Load Character Location."));

		if (!Character)
			return; // Ensure the character pointer is valid

		// Define the file path for loading the location
		FString LoadPath = FPaths::ProjectDir() / TEXT("Saved") / TEXT("CharacterLocation.sav");
		// Create a file reader object to read the data
		FArchive* FileArchive = IFileManager::Get().CreateFileReader(*LoadPath);
		if (FileArchive)
		{
			Character->Deserialize(*FileArchive); // Deserialize the location data from the file
			FileArchive->Close(); // Close the file to complete reading
			delete FileArchive; // Clean up the file archive object
		}
	}

};
