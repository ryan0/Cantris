local Player = {}

function Player.new()
    local self = {}
    self.Renderable = {
        zValue = 0
    }
    self.Animator = {
        position = {-7.5, -16.5},
        animations = {
            {"Walking", "player.lua"},
            {"Running", "player.lua", offset = {-7.5, 0}, frametime = 1/10},
            {"Jumping", "player.lua", offset = {-7.5, 0}, frametime = 1/10},
            {"Standing", "player.lua"}
        }
    }
    self.Spatial = {
        position = {0, 0},
        origin = {0, 0}
    }
    self.Physical = {
        b2BodyDef = {
            position = {0, 0},
            fixedRotation = true;
            type = "b2_dynamicBody"
        },
        b2FixtureDefs = {
            {
                density = 1.5,
                friction = 0.0,
                restitution = 0.0,
                b2CircleShape = {
                    radius = .5,
                    offset = {0, 1.3}
                }
            },
            {
                density = 2.0,
                friction = 0.0,
                restitution = 0.0,
                b2PolygonShape = {
                    setAsBox = {.49, 1.5},
                    offset = {0, -.2}
                }
            },
            {   --Grounded Sensor
                isSensor = true,
                density = 0.0,
                friction = 0.0,
                restitution = 0.0,
                b2PolygonShape = {
                    setAsBox = {.4, .25},
                    offset = {0, 1.8}
                }
            },
            {   --WallJump Sensor
                isSensor = true,
                density = 0.0,
                friction = 0.0,
                restitution = 0.0,
                b2PolygonShape = {
                    setAsBox = {.4, .25},
                    offset = {0, 1.8}
                }
            }
        }
    }
    self.Scriptable = {
        {
            script = "playerControl"
        }
    }
    return self
end

return Player