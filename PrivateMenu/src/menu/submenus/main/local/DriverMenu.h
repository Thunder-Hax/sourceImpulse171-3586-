#pragma once

class DriverMenu : public Submenu {
public:
	static DriverMenu* GetInstance();
	void Init() override;
	void UpdateOnce() override;
	void Update() override;
	void FeatureUpdate() override;

	DriverMenu() : Submenu() {}
	~DriverMenu();
};

namespace DriverMenuVars
{
	struct Vars {
			bool driveonair = false;
	};
}