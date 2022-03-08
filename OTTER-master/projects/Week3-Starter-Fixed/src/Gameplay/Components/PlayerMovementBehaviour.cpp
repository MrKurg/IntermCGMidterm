#include "PlayerMovementBehaviour.h"
#include <GLFW/glfw3.h>
#include "Gameplay/GameObject.h"
#include "Gameplay/Scene.h"
#include "Utils/ImGuiHelper.h"
#include "Gameplay/InputEngine.h"

void PlayerMovementBehaviour::Awake()
{
	_body = GetComponent<Gameplay::Physics::RigidBody>();
	if (_body == nullptr) {
		IsEnabled = false;
	}
}

void PlayerMovementBehaviour::RenderImGui() {
	LABEL_LEFT(ImGui::DragFloat, "Move", &_move, 1.0f);
}

nlohmann::json PlayerMovementBehaviour::ToJson() const {
	return {
		{ "move", _move }
	};
}

PlayerMovementBehaviour::PlayerMovementBehaviour() :
	IComponent(),
	_move(10.0f)
{ }

PlayerMovementBehaviour::~PlayerMovementBehaviour() = default;

PlayerMovementBehaviour::Sptr PlayerMovementBehaviour::FromJson(const nlohmann::json & blob) {
	PlayerMovementBehaviour::Sptr result = std::make_shared<PlayerMovementBehaviour>();
	result->_move = blob["move"];
	return result;
}

void PlayerMovementBehaviour::Update(float deltaTime) {
	//bool pressed = glfwGetKey(GetGameObject()->GetScene()->Window, GLFW_KEY_SPACE);
	_body->SetAngularFactor(glm::vec3(0.0f, 0.0f, 1.0f));

	if (glfwGetKey(GetGameObject()->GetScene()->Window, GLFW_KEY_D) == GLFW_PRESS)
	{
		_body->SetLinearVelocity(glm::vec3(-9.0f, 0.0f, 0.0f));
	}
	else if (glfwGetKey(GetGameObject()->GetScene()->Window, GLFW_KEY_A) == GLFW_PRESS)
	{
		_body->SetLinearVelocity(glm::vec3(9.0f, 0.0f, 0.0f));
	}
	else if (glfwGetKey(GetGameObject()->GetScene()->Window, GLFW_KEY_W) == GLFW_PRESS)
	{
		_body->SetLinearVelocity(glm::vec3(0.0f, -9.0f, 0.0f));
	}
	else if (glfwGetKey(GetGameObject()->GetScene()->Window, GLFW_KEY_S) == GLFW_PRESS)
	{
		_body->SetLinearVelocity(glm::vec3(0.0f, 9.0f, 0.0f));
	}
}
