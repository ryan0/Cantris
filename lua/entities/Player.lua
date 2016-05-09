local Player = {}

function Player.new(pos)
    local self = {}
    self.id = "Player"
    self.Renderable = {
        zValue = 0
    }
    self.Animator = {
        position = {-3.5, -4.5},
        animations = {
            {"Standing", "Animations/stand.ani"},
            {"Running", "Animations/run.ani"},
            {"Jumping", "Animations/jump.ani"},
            {"Death", "Animations/death.ani"},
            {"Crouching", "Animations/crouch.ani"},
            {"Crawling", "Animations/crawl.ani"}
        }
    }
    self.Spatial = {
        position = {0, 0},
        origin = {0, 0}
    }
    self.Physical = {
        b2BodyDef = {
            position = pos,
            fixedRotation = true;
            type = "b2_dynamicBody"
        },
        b2FixtureDef = {
            density = 1.0,
            friction = .5,
            restitution = 0.0,
            b2PolygonShape = {
                setAsBox = {0.8, 1.8}
            }
        }
    }
    self.Scriptable = {
        "playerControl"
    }
    return self
end

return Player