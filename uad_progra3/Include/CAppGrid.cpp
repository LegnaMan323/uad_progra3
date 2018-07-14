
#include "../Include/CAppGrid.h"



CAppGrid::CAppGrid()
{
	cout << "Constructor: CAppGrid()" << endl;

	//m_pWorld = new CWorld();
}

/* */
CAppGrid::CAppGrid(int window_width, int window_height) : CApp(window_width, window_height)
{
	cout << "Constructor: CAppGrid(int window_width, int window_height)" << endl;

//	m_pWorld = new CWorld();
}

CAppGrid::~CAppGrid()
{
	cout << "Destructor: ~CAppGrid()" << endl;
}

bool CAppGrid::initializeMenu()
{
	cout << "CAppGrid::initializeMenu()" << endl;

	return true;
}

void CAppGrid::initialize()
{
	// initialize del world
}

void CAppGrid::update(double deltaTime)
{
}

void CAppGrid::run()
{
	initialize();

	// Check if CGameWindow object and window library been initialized
	if (canRun())
	{
		// Create the Window 
	/*	if (getGameWindow()->create(CAPPHEXGRID_WINDOW_TITLE))
		{
			// Set initial clear screen color
			getOpenGLRenderer()->setClearScreenColor(0.15f, 0.75f, 0.75f);
			// Initialize window width/height in the renderer
			getOpenGLRenderer()->setWindowWidth(getGameWindow()->getWidth());
			getOpenGLRenderer()->setWindowHeight(getGameWindow()->getHeight());
			// Initialize a test cube
			getOpenGLRenderer()->initializeTestObjects();
			// Create our menu (add all menu items)

			m_pWorld->initialize(getOpenGLRenderer());
			if (!initializeMenu())
			{
				return;
			}

			// Enter main loop
			cout << "Entering Main loop" << endl;
			getGameWindow()->mainLoop(this);
		}*/
	}
}

void CAppGrid::render()
{
	CGameMenu *menu = getMenu();

	// If menu is active, render menu
	if (menu != NULL && menu->isInitialized() && menu->isActive())
	{
		menu->render(getOpenGLRenderer());
	}
	else // Otherwise, render active object if loaded (or test cube if no object is loaded)
	{
		// White 
		float color[3] = { 1.0f, 1.0f, 1.0f };

		// render del world
		//m_pWorld->render();
	
	}
}

void CAppGrid::executeMenuAction()
{
	if (getMenu() != NULL)
	{
	}
}

void CAppGrid::onMouseMove(float deltaX, float deltaY)
{
	if (deltaX < 100.0f && deltaY < 100.0f)
	{
	}
}