#pragma once
#include "IComponent.h"
#include "Gameplay/Physics/RigidBody.h"

class PlayerMovementBehaviour : public Gameplay::IComponent {
public:
	typedef std::shared_ptr<PlayerMovementBehaviour> Sptr;

	PlayerMovementBehaviour();
	virtual ~PlayerMovementBehaviour();

	virtual void Awake() override;
	virtual void Update(float deltaTime) override;

public:
	virtual void RenderImGui() override;
	MAKE_TYPENAME(PlayerMovementBehaviour);
	virtual nlohmann::json ToJson() const override;
	static PlayerMovementBehaviour::Sptr FromJson(const nlohmann::json& blob);

protected:
	float _move;

	bool _isPressed = false;
	Gameplay::Physics::RigidBody::Sptr _body;
};


